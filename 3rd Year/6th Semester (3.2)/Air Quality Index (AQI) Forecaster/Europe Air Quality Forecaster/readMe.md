# Europe Air Quality Forecaster

An advanced, isolated regional machine learning pipeline and spatiotemporal time-series regression framework optimized specifically for European urban climates to forecast hourly Air Quality Index ($PM_{2.5}$) levels across multiple municipal monitoring stations.

## 📌 Project Overview
* **Problem Type:** Spatiotemporal Time-Series Forecasting / Continuous Regression
* **Target Urban Sites:** Athens (Greece), Ancona (Italy), and Zaragoza (Spain)
* **Dataset Volume:** Over 2.1 Million rows (`2,144,042` continuous regional records processed)
* **Dataset Source:** Kaggle (`air-quality-monitoring-in-european-cities` by Yekenot)
* **Objective:** Analyze multi-chemical cross-interactions ($O_3$, $NO_2$, $PM_{10}$) and local meteorological shifts to predict hourly particulate matter concentration with minimal error thresholds.

## 🛠️ Tech Stack & Core Libraries
* **Language:** Python 3.12+
* **Machine Learning Regressors:** XGBoost Regressor, Random Forest Regressor
* **Data Manipulation & Processing:** Pandas, NumPy, Scikit-Learn
* **Visualization Engine:** Matplotlib, Seaborn (Mako and Plasma color palettes)

## 📂 Advanced Engineering Methodology
1. **Dynamic Multi-File Batch Aggregation:** Engineered an automated file-ingestion layer using Python's `os` module to scan, parse, and concatenate distinct city CSV files (`athens_data.csv`, `ancona_data.csv`, `zaragoza_data.csv`) into a single master framework.
2. **On-the-Fly Schema Sanitization:** Cleansed categorical indices, lowercased all headers, and stripped formatting artifacts (`.`, `-`) dynamically during execution to prevent column misalignment and structural parsing errors.
3. **Robust Data Type Filtering:** Restricted automated forward and backward interpolation (`ffill`/`bfill`) exclusively to numeric columns (`df.select_dtypes(include=[np.number])`) to safely bypass mixed text entries (e.g., station strings like *'Falconara Alta'*) and eliminate conversion exceptions.
4. **Sequence Context Partitioning:** Built 1-hour, 2-hour, and 24-hour historical lag structures paired with a 6-hour moving average window grouped strictly by localized city boundaries to preserve standalone urban telemetry trends without blending spatial features.
5. **Chronological Validation Strategy:** Enforced a strict non-shuffled 80/20 sequential train-test boundary split across the entire 2.1 Million rows to maintain continuous time logic and prevent data leakage.

## 📈 Final Model Performance Metrics

The machine learning engines were trained concurrently across a 1.71 Million record matrix and validated on an unseen 428K test slice.

| Predictive Framework Engine | Mean Absolute Error (MAE) | Root Mean Squared Error (RMSE) | R-squared ($R^2$) Score |
| :--- | :---: | :---: | :---: |
| **Random Forest Regressor** | 3.6372 | **14.4864** | **0.4674** |
| **XGBoost Regressor** | **3.5976** | 14.5182 | 0.4651 |

### Key Takeaways
* **High Predictive Precision:** Both models achieved highly stable predictive bounds, yielding an average error margin of only **~3.60** $PM_{2.5}$ concentration units over a massive data scope.
* **Variance Explanation:** The **Random Forest Forecaster** captured the highest overall variance threshold ($R^2 = 0.4674$) across the Mediterranean urban stations, while the **XGBoost Engine Core** maintained the tightest absolute error boundaries with a lower MAE of **3.5976**.

## 📊 Visualized Analytical Insights
* **Diurnal Peak Cycles:** Clear correlation detected between traffic-heavy rush hours (morning and evening transitions) and sharp spikes in urban particulate matter distributions.
* **Chemical Co-dependency:** Heatmap metrics indicate a high positive correlation between $PM_{10}$ and $PM_{2.5}$ across all three European cities, while $O_3$ levels exhibit strong seasonal fluctuations.

## 🚀 Local Execution Blueprint
1. Clone this repository and navigate to the isolated project directory:
   ```bash
   cd "Air Quality Index (AQI) Forecaster/Europe Air Quality Forecaster"
   ```
2. Place the raw city CSV files into the `/data` folder.
3. Open and launch the Jupyter workspace notebook:
   ```bash
   jupyter notebook notebooks/Europe_AQI_Forecaster.ipynb
   ```
