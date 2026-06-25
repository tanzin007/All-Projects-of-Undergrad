# 🚀 Stable Diffusion v2 LoRA Fine-Tuning on Custom Midjourney Dataset

An end-to-end, single-cell pipeline designed for Kaggle Notebooks to fine-tune Stable Diffusion v2 (Base) using Low-Rank Adaptation (LoRA) on custom image-prompt pairs. This repository completely automates dataset formatting, hardware optimization, and robust inference while eliminating common issues like `FP16 NaN` instabilities.

---

## ✨ Features

* **Automated Data Processing**: Dynamically pairs text descriptions (`.txt`) with corresponding images (`.jpg`/`.png`) and builds a structured dataset.
* **Smart Hardware Adaptability**: Auto-detects available computational resources and sets workflows for Apple/Cloud TPUs or NVIDIA GPUs.
* **Enhanced Stability (Anti-NaN)**: Uses locked Full Float32 precision routines across critical Cross-Attention and VAE Latent layers to avoid zero-underflow errors on Tesla T4 GPUs.
* **Single-Cell Execution**: Seamless one-click setup from framework installation to saving final adapters.

---

## 📂 Dataset Architecture

The pipeline expects a single root directory containing paired files with identical base names:
```text
Datasetfordream/
├── image_001.jpg
├── image_001.txt   <-- Contains raw text prompt inside
├── image_002.png
└── image_002.txt
```

---

## 🛠️ Step-by-Step Pipeline

### 1. Data Splitting & CSV Mapping
The script scans the shared input directory, copies all image elements into a clean isolated folder, extracts texts to populate metadata fields, and exports a structural map:
* `image name`: Filename references.
* `prompt`: The textual conditioning string.
* `image_path`: Absolute directory pointers for model mapping.

### 2. Latent Space Transformation
To bypass convolution dimension mismatches (`RuntimeError: Expected 4 channels, got 3`), raw RGB tensors are passed through a Variational Autoencoder (`AutoencoderKL`) to establish scaled 4-channel latents:
\[\text{Latents} = \text{VAE.encode}(\text{Pixels}) \times \text{Scaling Factor}\]

### 3. LoRA Attention Injection
Instead of processing all 867 Million parameters of the UNet backbone, LoRA adapters target the cross-attention blocks (`to_q`, `to_k`, `to_v`, `to_out.0`) with a rank configuration of r=8, reducing trainable parameters to just **0.19%** of the model!

---

## ⚙️ Hyperparameters

| Parameter | Configuration Value | Context / Reason |
| :--- | :--- | :--- |
| **Model Base** | `stabilityai/stable-diffusion-2-base` | Native 512x512 resolution pipelines |
| **Learning Rate** | `5e-5` | Safe optimization bounds for FP32 convergence |
| **Batch Size** | `1` | Optimized for Single-GPU Memory Limits |
| **Gradient Accumulation** | `4` | Simulates an effective batch size of 4 |
| **Max Training Steps** | `500` | Fast convergence on custom stylization |

---

## 🎨 Sample Inference Results

After training for 500 steps on a Tesla T4 GPU, the adapter successfully captured high-fidelity cyberpunk cinematic textures, dramatic lighting, and intricate structures:

* **Prompt Used**: `A cinematic, ultra-detailed cyberpunk street, neon lights, raining, masterpiece, 8k resolution`

---

## 💾 How to Use the Output

Once training finishes, your adapter weights are stored under `/kaggle/working/sdv2_lora_weights`. Run the following to pack them for external desktop deployment (e.g., Automatic1111 or ComfyUI):

```python
import shutil
shutil.make_archive('/kaggle/working/my_custom_lora', 'zip', '/kaggle/working/sdv2_lora_weights')
```

---

## 🧰 Requirements & Dependencies
* `torch` & `torchvision`
* `diffusers`
* `transformers`
* `accelerate`
* `peft` (Parameter-Efficient Fine-Tuning)
* `datasets`
* `tqdm`
