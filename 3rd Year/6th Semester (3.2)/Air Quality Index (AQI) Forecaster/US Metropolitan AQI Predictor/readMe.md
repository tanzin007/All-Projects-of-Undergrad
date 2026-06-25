# US Metropolitan AQI Predictor

An isolated regional machine learning pipeline and spatiotemporal time-series regression framework focused strictly on high-density American metropolitan setups to forecast hourly particulate matter ($PM_{2.5}$) and evaluate urban air safety standards.

## 📌 Project Overview
* **Problem Type:** Spatiotemporal Time-Series Forecasting / Continuous Regression
* **Target Metropolitan Hubs:** Sliced and filtered specifically for primary US urban centers (New York, Los Angeles, Chicago, Houston, Phoenix)
* **Dataset Source:** Kaggle (`global-air-quality-data15-days-hourly-50-cities` by Smeet888)
* **Objective:** Capture continuous micro-variance indicators within close-proximity city sensor grids influenced by heavy vehicular traffic emissions and urban diurnal heat islands.

## 🛠️ Tech Stack & Core Libraries
* **Language:** Python 3.12+
* **Predictive Framework Engines:** RandomForestRegressor, XGBoost Regressor
* **Data Engineering Stack:** Pandas, NumPy, Scikit-Learn
* **Visualization Suite:** Matplotlib, Seaborn (Coolwarm palette mappings)

## 📂 Advanced Engineering Methodology
1. **Target Geospatial Slicing:** Processed incoming global city rows, stripping trailing whitespace artifacts, and isolating rows matching the United States mainland territory bounds.
2. **Robust Categorical Data Isolation:** Grouped target data structures by localized city labels and routed forward/backward series fills (`ffill`/`bfill`) strictly through numeric vectors to eliminate typing format and object conversion errors.
3. **Diurnal Factor Engineering:** Deconstructed raw timestamps into explicit temporal indices (`Hour`, `DayOfWeek`, `Month`) to analyze vehicular rush-hour emissions and cyclical human activities.
4. **Historical Sequence Memory:** Engineered 1-hour, 2-hour, and 24-hour shifting lag metrics paired with a 6-hour moving average window grouped safely by individual US cities to maintain chronological patterns without cross-regional data bleeding.
5. **Time-Series Validation Setup:** Applied a strict chronological 80/20 non-shuffled partition matrix split to validate real-time inference handling without temporal data leakage.

## 📈 Final Model Performance Metrics (US Region)

The machine learning engines were validated on an unseen evaluation slice across the targeted US metropolitan hubs, yielding high-accuracy predictive boundaries:

| Predictive Framework Engine | Mean Absolute Error (MAE) | Root Mean Squared Error (RMSE) | R-squared ($R^2$) Score |
| :--- | :---: | :---: | :---: |
| **Random Forest Regressor** | **8.2142** | **11.6653** | **0.5424** |
| XGBoost Regressor | 8.5786 | 12.1294 | 0.5052 |

### Key Takeaway
Unlike the European model, the **Random Forest Regressor** demonstrated superior efficiency on the US dataset, capturing a higher variance threshold ($R^2 = 0.5424$) and maintaining the tightest absolute error boundaries with a lower MAE of **8.2142**. This indicates that ensemble bagging was highly effective at smoothing out localized micro-variance indicators within the close-proximity US city sensor grids.

## 📊 Visualized Analytical Insights
* **US Rush Hour Effect:** Pointplot analysis reveals sharp fluctuations in $PM_{2.5}$ concentration corresponding to urban peak commuting windows.
* **Pollutant Volatility:** Residual error distribution density mappings confirm a balanced tracking stability, proving that historical lag attributes provided robust context to the regressor trees.

## 🚀 Local Execution Blueprint
1. Clone this repository and navigate to the isolated project directory:
   ```bash
   cd "Air Quality Index (AQI) Forecaster/US Metropolitan AQI Predictor"
   ```
2. Place the raw `globalAirQuality.csv` file inside the `/data` folder.
3. Open and launch the Jupyter workspace notebook:
   ```bash
   jupyter notebook notebooks/US_Metropolitan_AQI_Predictor.ipynb
   ```
