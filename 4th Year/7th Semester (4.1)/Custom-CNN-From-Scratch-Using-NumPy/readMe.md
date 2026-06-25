# Custom CNN From Scratch Using NumPy

This notebook contains a pure, framework-free implementation of a Convolutional Neural Network (CNN) engineered to classify handwritten digits from the MNIST dataset. By bypassing high-level deep learning libraries, this project exposes the raw mathematical mechanics, matrix operations, and gradient propagation pipelines that drive deep learning foundational networks.

## 📊 Architectural Specification
The network architecture is mathematically balanced to hit a lightweight footprint of approximately **10,000 parameters**:
1. **Input Space:** 28x28 Grayscale Image Matrices.
2. **Convolutional Block (Conv3x3):** 6 independent filters (3x3 Kernel size) $\rightarrow$ Processing feature maps down to `26x26x6`.
3. **Subsampling Block (MaxPool2):** 2x2 Spatial windowing with a Stride of 2 $\rightarrow$ Compressing maps down to `13x13x6`.
4. **Classification Block (Softmax Layer):** Flattens the remaining 1,014 activation values into a Multi-Class Softmax Dense array mapping to 10 numerical targets (0-9).

## ⚙️ Core Technical Capabilities
* **Zero Deep Learning Frameworks:** Built exclusively using standard Python loops and vectorized matrix calculations via `NumPy`.
* **Numerical Stabilization Strategy:** Implements an exponential scaling shift (`totals - np.max(totals)`) within the Softmax activator to actively eliminate runtime overflows (`NaN` / `Inf`).
* **Heuristic Parameter Initialization:** Filters and node weights are normalized against input layer shapes (`np.random.randn(...) / input_len`) to suppress exploding or vanishing gradients.

## 📈 Model Performance & Validation
* **Dataset Partitioning:** Evaluation setup utilizing a random strict **70% Training / 15% Validation / 15% Testing** data split over a 3,000 sample window.
* **Live Progress Feedback:** Utilizes `tqdm` integration to monitor sample batch loop velocities and runtime loss values in real-time.
* **Optimization Cycles:** Trained over **4 complete epochs**.
* **Final Test Accuracy:** **91.78%** on completely unseen evaluation data splits.

## 🎨 Statistical Visualizations Included
* **Convergence Diagnostics:** Dual trend graphs logging Training vs. Validation Loss and Accuracy variations per cycle.
* **Error Heatmaps:** A specialized high-contrast `magma` matrix visual plotting inter-class token correlation errors.
* **Prediction Grid:** An interactive `plasma` formatted canvas printing validation image tiles with distinct green/red prediction status flags.
