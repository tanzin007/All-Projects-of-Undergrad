# Advanced Heavy CNN Using PyTorch

This notebook implements a heavy-parameter Deep Convolutional Neural Network (CNN) leveraging the PyTorch API framework. It is structurally engineered to evaluate intensive parameter scaling, batch optimization pipelines, and production-grade parallel computing using modern hardware accelerators over the full MNIST dataset.

## 📊 Architectural Specification
The network pipeline contains deep feature blocks scaling structural parameters to exactly **~20.1 Million parameters**:
1. **Convolutional Extraction Block:** 
   * Layer 1: 2D Convolution (1 Input $\rightarrow$ 64 Output channels, 3x3 Kernel).
   * Regularization: 2D Batch Normalization + ReLU Activation.
   * Layer 2: 2D Convolution (64 Input $\rightarrow$ 128 Output channels, 3x3 Kernel) + ReLU.
   * Subsampling: 2D Max Pooling over a 2x2 grid $\rightarrow$ Outputs an array dimension of `128x14x14`.
2. **Heavy Classifier Blocks:** 
   * Fully Connected scaling layer expanding `128 * 14 * 14` (25,088 input connections) up to 800 dense hidden neurons.
   * Overfitting Mitigation: Dropout protection layer initialized at a 30% drop-probability rate (0.3).
   * Secondary compression dense layer mapping 800 units down to 128 features.
   * Final Output: Linear projection layers mapping to 10 categorical numerical scores.

## ⚙️ Core Technical Capabilities
* **Hardware Accelerator Optimization:** Full orchestration of tensors mapped via the `torch.device('cuda')` API layer to leverage NVIDIA GPU streaming architectures.
* **Advanced Multi-Batch Pipelines:** Asynchronous data streaming utilizing structured PyTorch `DataLoader` modules with regular batch segments of 128 elements.
* **State-of-the-Art Optimization:** Integrates Cross-Entropy loss structures controlled by the `Adam` gradient optimizer engine (`learning_rate=0.001`).

## 📈 Model Performance & Validation
* **Dataset Partitioning:** Full dataset coverage using a strict **70% Training (42k images) / 15% Validation (9k images) / 15% Testing (9k images)** segmentation split strategy.
* **Optimization Cycles:** Optimized over **3 complete epochs** (Execution time: ~5 seconds per epoch on T4 GPU).
* **Final Test Accuracy:** **98.60%** achieving production-grade accuracy metrics.

## 🎨 Statistical Visualizations Included
* **Optimization Convergence Tracking:** Detailed comparative curves for Cross-Entropy Loss decay and Accuracy step scales for both train and validation phases.
* **Icefire Heatmaps:** A dark-tech `icefire` color-gradient confusion matrix illustrating deep-layer prediction confidence vectors across digits.
* **Inference Matrix Canvas:** Grids of predictive test targets visualized under a modern `plasma` colormap configuration with real-time success highlighting.
