# Global Metropolitan AQI Predictor (50 Cities Bundle)

An advanced machine learning pipeline and spatiotemporal time-series regression framework built on a high-volume, multi-national telemetry network to forecast hourly particulate matter ($PM_{2.5}$) levels across 50 international macro cities.

## 📌 Project Overview
* **Problem Type:** Spatiotemporal Time-Series Forecasting / High-Dimensional Continuous Regression
* **Target Scope:** 50 major global metropolitan centers across multiple continents (e.g., Tokyo, London, Paris, New York, Delhi, Sydney).
* **Dataset Volume:** 18,000 global continuous telemetry rows processed.
* **Dataset Source:** Kaggle (`global-air-quality-data15-days-hourly-50-cities` by Smeet888)
* **Objective:** Benchmark and validate the generalization capabilities of competitive tree-based ensembles when tracking atmospheric volatility across completely divergent industrial regulations and regional climate profiles.

## 🛠️ Tech Stack & Core Libraries
* **Language Environment:** Python 3.12+
* **Algorithmic Engines:** RandomForestRegressor, XGBoost Regressor
* **Data Engineering Stack:** Pandas, NumPy, Scikit-Learn (Preprocessing & Metrics Modules)
* **Visualization Suite:** Matplotlib, Seaborn (Custom Turbo palette mappings)

## 📂 Advanced Engineering Methodology
1. **Multi-National Ingestion Sanitization:** Processed massive global sensor telemetry logs, stripped trailing spatial index artifacts, and unified mismatched column headers into a universal lowercase schema.
2. **Robust Categorical Data Isolation:** Grouped target data structures by localized city labels and routed forward/backward series fills (`ffill`/`bfill`) strictly through numeric vectors to eliminate typing format and object conversion errors during aggregation.
3. **High-Cardinality Label Encoding:** Utilized Sklearn's `LabelEncoder` to transform complex nominal location tokens (`city` and `country`) into numerical input layers without expanding feature dimensionality, safely bypassing memory faults caused by traditional dummy variables.
4. **Volatility Feature Engineering:** Extracted cyclical temporal indicators (`Hour`, `DayOfWeek`, `Month`) and engineered 1-hour, 2-hour, and 24-hour historical lag structures paired with a 6-hour moving standard deviation ($Rolling\_Std$) to capture rapid atmospheric shifts.
5. **Sequential Leakage Prevention:** Applied a strict chronological 80/20 non-shuffled partition matrix split to validate real-time inference handling without temporal data leakage.

## 📈 Final Model Performance Metrics (Global 50-Cities Scope)

The machine learning engines were cross-validated simultaneously across 50 international municipal centers, generating highly resilient predictive benchmarks:

| Predictive Framework Engine | Mean Absolute Error (MAE) | Root Mean Squared Error (RMSE) | R-squared ($R^2$) Score |
| :--- | :---: | :---: | :---: |
| **Random Forest Regressor** | **6.8238** | **10.1724** | **0.6590 (65.9%)** |
| XGBoost Regressor | 6.9808 | 10.2452 | 0.6541 (65.4%) |

### Advanced Modeling Insights
Expanding the matrix architecture from a localized slice to a high-volume global pipeline drastically optimized model stability. The **Random Forest Forecaster Engine** capitalized effectively on high-cardinality label encodings, boosting continuous predictive accuracy to **65.90% ($R^2 = 0.6590$)** while scaling down error variances to a low MAE of **6.8238**. This structurally confirms that expanding sample sizes and diversifying regional profiles dramatically mitigates tree overfitting.

## 📊 Core Insights Captured
* **Global Diurnal Emission Waves:** Continuous lineplot diagnostics show universal atmospheric fluctuations corresponding directly to global rush-hour cycles, independent of geographic locations.
* **Resilient Deviation Error Fields:** Kernel Density Estimation (KDE) maps of model residuals show a tight distribution around the zero-error line, confirming high inference reliability under intense spatiotemporal scaling.

## 🚀 Local Execution Blueprint
1. Clone this repository and navigate to the isolated project directory:
   ```bash
   cd "Air Quality Index (AQI) Forecaster/Global Metropolitan AQI Predictor"
   ```
2. Place the raw `globalAirQuality.csv` file inside the `/data` folder.
3. Open and launch the Jupyter workspace notebook:
   ```bash
   jupyter notebook notebooks/Global_Metropolitan_AQI_Predictor.ipynb
   ```
