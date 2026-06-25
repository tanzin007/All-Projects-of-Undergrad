# 🫀 Heart Disease Risk Classifier (Predictive Diagnostics)

[![Python](https://shields.io)](https://python.org)
[![Framework](https://shields.io)](https://scikit-learn.org)
[![Topic](https://shields.io)](https://uci.edu)

An end-to-end Machine Learning classification framework designed to analyze clinical, physiological, and lifestyle telemetry to detect cardiovascular disease risk. Built using the structured 14-attribute subset of the famous multi-center UCI Heart Disease Database.

---

## 📌 Project Architecture

*   **Target Feature:** `num` (Transformed to Binary classification: `0` = No Risk, `1` = High Risk Presence).
*   **Dataset Source:** [UCI Heart Disease Dataset (via Kaggle)](/kaggle/input/datasets/redwankarimsony/heart-disease-data/heart_disease_uci.csv)
*   **Pipeline Split:** Strict **70/15/15** Holdout Split stratifying target balance across Train (644 samples), Validation (138 samples), and Test sets (138 samples).
*   **Missing Value Strategy:** Implemented a robust statistical Imputation workflow (Median for Continuous features, Mode for Categorical features) minimizing diagnostic information loss.

---

## 🔬 Clinical Attributes Tracked

The predictive pipeline maps 14 critical parameters categorized below:
*   **Demographics:** `age`, `sex`
*   **Symptomatic Data:** `cp` (Chest pain topology: Typical, Atypical, Non-anginal, Asymptomatic), `exang` (Exercise-induced angina)
*   **Vascular Data:** `trestbps` (Resting blood pressure), `chol` (Serum cholesterol), `fbs` (Fasting blood sugar thresholds)
*   **Electrocardiographic (ECG):** `restecg`, `thalch` (Max heart rate achieved), `oldpeak` (ST depression), `slope`
*   **Fluoroscopy & Scintigraphy:** `ca` (Colored major vessels), `thal` (Thalassemia screening metrics)

---

## 🤖 Model Performance & Evaluation

Because this is a healthcare intervention application, **Recall (Sensitivity)** is prioritized as the core optimization metric alongside **F1-Score**. Minimizing False Negatives (failing to identify an at-risk cardiac patient) is paramount to patient safety.

### 📊 Performance Benchmarking (Unseen Test Set)

| Model Configuration | Test Accuracy | Test Recall (Sensitivity) | Final F1-Score | Performance Status |
| :--- | :---: | :---: | :---: | :---: |
| 🥇 **Decision Tree Classifier** | **0.8261** | **0.8158** | **0.8378** | 🏆 **Champion Model** |
| 🥈 Random Forest Classifier | 0.8116 | 0.8421 | 0.8312 | Benchmarked Model |
| 🥉 Logistic Regression | 0.8116 | 0.8158 | 0.8267 | Benchmarked Model |

### 💡 Crucial Clinical Insight
The **Decision Tree Classifier** emerged as the overall champion with an F1-Score of **83.78%** due to its balanced precision-recall matrix. However, the **Random Forest** framework demonstrated the highest clinical safety margin with a **Recall of 84.21%**, meaning it successfully caught more at-risk patients than the other models, making it a strong candidate for screening-first workflows where minimizing missed cases is crucial.

---

## 📊 Comprehensive Visualizations Implemented

The automated workflow compiles and outputs an advanced multi-pane structural analytics suite:
*   **Dataset Class Distribution Plot:** A pie chart confirming target feature distribution (`No Risk` vs `Risk`) to track data balance.
*   **Age Density Distribution Curve:** Evaluates cardiac risk trends across patient lifespans through overlapping Kernel Density Estimate (KDE) layers.
*   **Receiver Operating Characteristic (ROC) Curve:** Plots True Positive Rate vs False Positive Rate, tracking AUC score to prove how effectively the models separate healthy records from at-risk instances.
*   **Confusion Matrix Heatmap:** Graphs precise Diagnostic True Positives vs False Negatives to evaluate the healthcare system's safety margin.
*   **Top 10 Risk Indicator Plot:** Ranks physiological traits based on their mathematical weight coefficients to isolate immediate risk factors.

---

## 🚀 Technical Requirements & Local Setup

To replicate or review the pipeline locally, clone the workspace and install standard requirements:

```bash
pip install pandas numpy matplotlib seaborn scikit-learn
```

### Script Execution
Map your explicit local path variables directly into the input block and run the notebook cells sequentially to compile all pipelines and advanced visuals instantly.

---

## 📈 My Machine Learning Journey

This project marks my transition into **Supervised Machine Learning Classification Frameworks**. It helped cultivate practical competencies in structured clinical pre-processing, statistical data imputation methods, one-hot dummy matrix operations, and diagnostic metric optimization protocols within high-stakes industrial boundaries.
