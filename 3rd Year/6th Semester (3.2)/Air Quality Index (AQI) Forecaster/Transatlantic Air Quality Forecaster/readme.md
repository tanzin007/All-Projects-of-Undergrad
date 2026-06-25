# Transatlantic Air Quality Forecaster (US vs Europe)

An advanced machine learning and spatiotemporal time-series regression project that integrates multi-source continuous atmospheric telemetry to forecast hourly Air Quality Index (PM2.5) levels across major European and American urban centers.

## 📌 Project Overview
* **Problem Type:** Time-Series Forecasting / Continuous Regression
* **Objective:** Predict upcoming hourly PM2.5 concentrations and analyze seasonal/diurnal pollution dynamics across continents.
* **Dataset Volume:** Over 2 Million rows (`2,099,692` records processed)
* **Datasets Used (Kaggle Paths):**
  1. `/kaggle/input/datasets/yekenot/air-quality-monitoring-in-european-cities` (Athens, Ancona, Zaragoza)
  2. `/kaggle/input/datasets/smeet888/global-air-quality-data15-days-hourly-50-cities` (Filtered for major US Metro areas)

## 🛠️ Tech Stack & Core Libraries
* **Language:** Python 3.12
* **Machine Learning Regressors:** XGBoost Regressor, Random Forest Regressor
* **Data Engineering & Analytics:** Pandas, NumPy, Scikit-Learn
* **Data Visualization Suite:** Matplotlib, Seaborn (Turbo & Coolwarm palettes)

## 📂 Data Engineering & Methodology
1. **Dynamic Batch Extraction:** Implemented on-the-fly multi-file loading via Python's `os.walk` to merge divergent regional sensor schemas.
2. **String Preprocessing & Sanitization:** Cleansed categorical indices and stripped special characters (`.`, `-`) dynamically upon ingestion to avoid schema alignment failures (`KeyError`).
3. **Temporal Cycle Extraction:** Extracted transactional cycles including `Hour`, `DayOfWeek`, and `Month` to map cyclical human activities and rush hours.
4. **Historical Sequence Memory:** Engineered 1-hour, 2-hour, and 24-hour shifting lag vectors alongside a 6-hour moving average window grouped by local cities to capture temporal dependencies without blending spatial regions.
5. **Chronological Validation Strategy:** Utilized a strict temporal train-test split (80/20 non-shuffled cutoff) to replicate a real-world testing environment and completely prevent future data leakage.

## 📈 Final Model Performance Metrics

The algorithms were trained concurrently across a 1.67 Million record matrix and validated on an unseen 419K evaluation slice.

| Predictive Engine Core | Mean Absolute Error (MAE) | Root Mean Squared Error (RMSE) | R-squared (R²) Score |
| :--- | :---: | :---: | :---: |
| **XGBoost Regressor** | **5.6001** | **16.2356** | **0.2391** |
| Random Forest Regressor | 5.6027 | 16.2977 | 0.2332 |

### Key Takeaway
The **XGBoost Engine Core** marginally outperformed the Random Forest Regressor across all primary validation metrics. With a Mean Absolute Error of **~5.60**, the model exhibits highly stable predictive error thresholds for global multi-station telemetry tracking under high-variance time-series shifts.

## 📊 Core Insights Captured
* **Diurnal Cycles:** Clear correlation detected between traffic rush hours (morning/evening) and sudden shifts in micro-pollutant density profiles.
* **Regional Discrepancies:** European cities (Athens context) and US Metros show highly divergent variance trends driven by localized industrial regulations and meteorological parameters.

## 🚀 How to Execute Locally
1. Clone this repository or locate the specific project directory:
   ```bash
   cd "Transatlantic Air Quality Forecaster"
   ```
2. Place your raw dataset files inside the `/data` folder.
3. Open and trigger the Jupyter notebook located in the notebooks directory:
   ```bash
   jupyter notebook notebooks/Transatlantic_AQI_Forecaster.ipynb
   ```
