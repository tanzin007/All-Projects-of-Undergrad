# 🐾 Conditional GAN (cGAN) Text-to-Image Generator from Scratch

A clean PyTorch implementation of a **Conditional Generative Adversarial Network (cGAN)** designed to generate 64×64 resolution pet images based on text labels (class conditions). The project is trained on the **Oxford-IIIT Pet Dataset** and optimized to automatically choose between Kaggle Cloud TPU, GPU, or CPU accelerators.

---

## 🛠️ Project Architecture (~6M Parameters)

Unlike a standard GAN that generates random images from pure noise, this **Conditional GAN (cGAN)** takes both a random noise vector and a specific class label (text prompt) as inputs. This allows you to control exactly which breed of cat or dog the model should generate.

* **The Latent Space (Z):** 100-dimensional random Gaussian noise vector combined channel-wise with 32-dimensional text/class embeddings.
* **Generator:** A deep convolutional network that projects input tensors into spatial blocks (512 × 4 × 4) and uses Batch Normalization and 2D Transposed Upsampling blocks to scale up to a clean 64 × 64 × 3 image output bounded by `nn.Tanh()`.
* **Discriminator:** A binary convolutional classifier utilizing strided LeakyReLU filters (0.2 slope) to evaluate if an image is real or fake, conditioned on the spatial layout of the input text label.

---

## 📊 Training Dynamics & The Epoch 35 Crossover

Adversarial training requires a delicate balance between the Generator and the Discriminator. This project highlights a critical machine learning lesson regarding model convergence:

### 🏁 Milestone 1: Epoch 35 (Optimal Balanced Equilibrium)
At this stage, the training reached a perfect equilibrium:
* **Generator Loss (G_Loss):** Stable oscillation between `1.37` and `2.40`.
* **Discriminator Loss (D_Loss):** Firmly locked at `0.3622`.
* **Visual Results:** Visual pixel boundaries are highly compressed and **extremely sharp**. The model accurately maps distinctive animal shapes, ear angles, and postures in a **single forward step** (instant inference).

### 🛑 Milestone 2: Epoch 50 (Total Mode Collapse & Overfitting)
Extending the training to 50 epochs triggered a text-book **Mode Collapse**:
* **Discriminator Loss (D_Loss):** Crashed to `0.0005` (The discriminator became too dominant and easily rejected all generated fakes).
* **Generator Loss (G_Loss):** Spiked to `8.8088` (The generator completely fractured and failed to backpropagate meaningful spatial updates).
* **The Outcome:** Pushing training iteration counts higher does not guarantee better results in GAN frameworks. Saving and deploying the checkpoint at the exact convergence crossover (**Epoch 35**) is mandatory for optimal results.

---

## 🚀 How to Load and Execute

Since the entire model architecture was serialized during the optimal epoch checkpoint, you can bypass the corrupted 50-epoch configuration and run the inference code in any fresh blank Python script with **zero class code dependencies**:

```python
import torch
import numpy as np
import matplotlib.pyplot as plt

# 1. Automatic hardware allocation
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# 2. Load the optimal 35-epoch generator object directly 
generator = torch.load("custom_6m_generator_pet_35epochs.pth", map_location=device, weights_only=False)
generator.eval()

# 3. Sample 4 random image tensors instantly via single forward pass
LATENT_DIM = 100
z = torch.randn(4, LATENT_DIM, device=device)
dummy_labels = torch.zeros(4, dtype=torch.long).to(device)

with torch.no_grad():
    generated_images = generator(z, dummy_labels)

# 4. Denormalize and render output grids
generated_images = (generated_images.clamp(-1, 1) + 1.0) / 2.0
generated_images = generated_images.cpu().permute(0, 2, 3, 1).numpy()

fig, axes = plt.subplots(1, 4, figsize=(12, 4))
for i in range(4):
    axes[i].imshow(generated_images[i])
    axes[i].axis('off')
plt.show()
```

---
