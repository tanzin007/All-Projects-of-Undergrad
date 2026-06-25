# 🐾 Multi-Modal Generative AI Architecture: Custom 53M Parameter Diffusion Model

An advanced Deep Learning repository showcasing the mathematical implementation, architectural design, and optimization of a Generative Text-to-Image Pipeline from scratch. This project forms the core foundation of my 7th and 8th-semester computing portfolio, transitioning from fundamental neural theory to high-performance hardware acceleration.

---

## 🚀 Portfollio Context & Structural Breadth
To demonstrate complete mastery over Deep Learning frameworks, mathematical optimization, and multi-modal engineering, my academic portfolio is structured into a distinct multi-phase roadmap:

1. **7th Semester (Core Foundations):** Written from scratch using pure NumPy to understand analytical gradient flows, backpropagation calculus, and standard parameter constraints without reliance on automated framework tracking.
2. **Framework Evaluation (PyTorch/TensorFlow CNNs):** Transitioning core structural principles into native production environments using optimized standard industry blocks.
3. **NLP Foundations (25M Custom Packed SLM):** Developing specialized sequence tokens and sequence chunk packing mechanisms to optimize training bounds in tight resource constraints.
4. **8th Semester (Multi-Modal Vision - This Repository):** Developing a fully custom **53 Million Parameter Denoising Diffusion Probabilistic Model (DDPM)** from scratch to bridge NLP (Time/Text Conditioning tokens) and Generative Computer Vision.

---

## 🛠️ Phase 1 Architecture: Custom 53M DDPM UNet
Instead of using fine-tuned open-source model configurations (like Stable Diffusion), **Phase 1 of this project builds the entire multi-modal pipeline from absolute scratch.** 

### 📐 Mathematical Pipeline Design
* **Forward Noise Process (Noising):** Implementing Markov chains according to standard DDPM schedules (T=1000 steps) utilizing localized variance boundaries (\(\beta_s = 1e-4\) to \(\beta_e = 0.02\)).
* **Reverse Denoising Process (The UNet Core):** Re-architecting a heavily customized 53 Million Parameter deep UNet utilizing residual shortcut dimensions, structural channel scaling (128 → 256 → 512 → 512), and localized **Multi-Head Self-Attention Blocks** inside bottleneck processing regions.
* **Multi-Modal Conditioning Loop:** Injecting joint Sinusoidal Timestep Embeddings combined with explicit Text Class Tokens directly across down-sampling and up-sampling spatial blocks via linear projection layers.

### 📊 Dataset & Distributed Compute Infrastructure
* **Dataset Target:** The official *Oxford-IIIT Pet Dataset* consisting of roughly ~7,400 high-resolution multi-breed color image tags. 
* **Input Transformation Dimensions:** All images are normalized via random horizontal augmentations and explicitly mapped directly into 64 × 64 × 3 color channels.
* **Distributed Compute Scaling:** The initial base execution line (1 → 70 epochs) was trained under constrained VRAM allocations on Google Colab (Free T4 GPU Tier). To complete extensive scaling validation without graph allocation crashes, the state dictionary weights were serialized and migrated to **Kaggle's Cloud TPU (Tensor Processing Units)** architecture to achieve structural completion over **300 full continuous epochs**.

---

## 📉 Convergence History & Generation Evolution

Training high-capacity diffusion pipelines from scratch requires massive parameter optimization steps. Over 300 epochs of continuous backward training passes, the mean squared error (MSE) loss reduced smoothly, signaling architectural stability:
* **Epoch 1:** Average Loss ≈ `0.1564` (Raw structural entropy)
* **Epoch 70:** Average Loss ≈ `0.0242` (Boundary edges and background canvas separation clear)
* **Epoch 300 (Final TPU Milestone):** Average Loss ≈ `0.0214` (Localized texture maps and basic animal geometry stabilized)

### 🖼️ Evolution Sampling Matrix
* **At 30 Epochs:** Visual outputs generate high-frequency chromatic aberrations and raw color blobs. The model has mapped standard noise boundaries but fails to locate spatial coordinates for animal profiles.
* **At 70 Epochs:** Chromatic noise drops significantly. Distinct visual silhouettes and spatial geometry contours (e.g., animal body lines, structural postures) emerge clearly against contrast-mapped canvases.
* **At 300 Epochs:** High-frequency visual boundaries compress into structured textual patterns. The model generates distinct categorical layouts matching text conditions (e.g., Cat profiles vs Dog postures) with highly structured color fills.

---

## 🔮 Production Readiness & Code Execution

To prevent strict code dependency overheads during downstream production environments or inference containers, this model is built for native multi-platform compatibility:

### 1. Standalone Direct Execution
To reconstruct the compiled model structure inside blank python virtual environments without storing full architecture classes, place the matching module template shell configuration inside `__main__` memory before unpacking the checkpoint file:
```python
import torch

# Restore layout mapping tokens inside active main memory
class TimeClassEmbedding(torch.nn.Module):
    def __init__(self, dim, num_classes): super().__init__(); def forward(self, x, y): pass
class ResidualBlock(torch.nn.Module):
    def __init__(self, in_channels, out_channels, emb_dim): super().__init__(); def forward(self, x, y): pass
class Custom20MUNet(torch.nn.Module):
    def __init__(self, num_classes): super().__init__(); def forward(self, x, t, class_idx): pass

# Safely unpickle the 300-epoch full model configuration 
model = torch.load("custom_53m_diffusion_pet_300epochs.pth", map_location="cuda", weights_only=False)
model.eval()
```

### 2. TorchScript Optimization Pipeline (Provisional)
By utilizing optimized `JIT Tracing` frameworks, the model’s logical execution tracks can be locked into unified low-level binary graphs. This allows for direct single-line pipeline evaluation:
```python
# Zero dependencies on original python module classes
model = torch.jit.load("custom_53m_diffusion_pet_torchscript.pt", map_location="cuda")
```
