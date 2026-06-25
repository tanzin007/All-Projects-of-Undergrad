# 🎓 Student Performance Predictor (Regression Study)

An end-to-end Machine Learning research project designed to analyze and predict student exam scores based on diverse academic, socioeconomic, and lifestyle factors. This project implements advanced feature engineering, strict validation partitioning, and robust multi-model benchmarking.

## 📌 Project Overview
* **Target Variable:** `Exam_Score` (Continuous)
* **Dataset Size:** 6,378 student records (after preprocessing)
* **Data Split:** Strict 70/15/15 Train-Validation-Test paradigm (No Data Leakage)
* **Champion Model:** **Linear Regression** (Achieved **74.34%** explanatory variance on unseen test data)

---

## 🛠️ Key Features Engineered
To capture deeper underlying behavioral dynamics, three customized domain-specific interaction metrics were developed:
1. **`Total_Study_Effort`**: Combined weekly hours studied and monthly tutoring exposure.
2. **`Lifestyle_Index`**: Evaluated holistic student well-being combining sleep hours and physical activity.
3. **`Attendance_Score_Interaction`**: Interactive multiplier tracking how attendance percentages scale alongside historical academic grades.

---

## 🤖 Experimental Architecture & Results

This project benchmarks traditional frameworks against state-of-the-art (SOTA) ensemble models. Models were strictly cross-validated using **5-Fold CV** and evaluated against unseen test configurations.

### Performance Leaderboard (Test Data Evaluated)

| Model Architecture | Mean Squared Error (MSE) | R-squared Score (Accuracy) | Status |
| :--- | :---: | :---: | :---: |
| **Linear Regression** | **4.0958** | **0.7434** | 🏆 **Champion** |
| Optimized XGBoost | 4.4793 | 0.6938 | Benchmarked |
| LightGBM Regressor | 4.5130 | 0.6915 | Benchmarked |
| Random Forest Regressor | 5.8143 | 0.6026 | Overfitted |

### 💡 Crucial Analytical Insight
While complex tree-based frameworks (`XGBoost`, `Random Forest`) are routinely favored in structured data competitions, **Linear Regression emerged as the absolute champion** for this study. This proves a highly linear underlying trajectory connecting student support infrastructure and final grades, demonstrating that complex models are prone to unnecessary overfitting on highly behavioral features.

---

## 📊 Core Visualizations Implemented
The automated workflow automatically compiles and outputs a multi-pane structural analytics suite:
* **Correlation Heatmap**: Maps the exact multi-collinear and independent mathematical paths between numeric variables.
* **Feature Importance Chart**: Rank-orders every single structural feature by its absolute predictive coefficient weight to highlight the highest areas of social or economic impact on education.
* **Distribution and Structural Variance Plots**: Investigates distribution behaviors using automated distribution curves and box plots.

---

## 🔑 Top 5 Most Influential Features
Based on the absolute structural coefficient weights, the top 5 parameters driving academic variance include:
1. **Attendance** (+1.8614) `[Strongest Positive Impact]`
2. **Total_Study_Effort** (+0.9323) `[Engineered Feature - Positive Impact]`
3. **Hours_Studied** (+0.8755) `[Positive Impact]`
4. **Access_to_Resources_Low** (-0.8365) `[Highest Negative Impact]`
5. **Parental_Involvement_Low** (-0.8140) `[Strong Negative Impact]`

---

## 🚀 Technical Requirements & Execution

To replicate or review the pipeline locally, clone the workspace and install standard requirements:

```bash
pip install pandas numpy matplotlib seaborn scikit-learn xgboost lightgbm
```

### Execution
Simply load the dataset path mapping inside your notebook interface and execute the cells sequentially to trigger the advanced feature pipeline, hyperparameter searches, and evaluation blocks automatically.

---

## 📈 My Machine Learning Journey
This project was constructed as part of my advanced exploration into **Regression Analysis**. It reinforces critical data science skills including data cleansing, explicit pipeline orchestration, feature engineering, structural optimization via cross-validation, and performance evaluation under industrial constraints.
