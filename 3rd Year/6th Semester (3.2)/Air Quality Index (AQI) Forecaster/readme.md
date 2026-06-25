# 🌤️ Air Quality Index (AQI) Forecasting Core

This directory contains a suite of advanced machine learning pipelines and spatiotemporal time-series regression projects dedicated to monitoring and forecasting hourly Air Quality Index ($PM_{2.5}$) levels. It hosts combined global models alongside isolated regional architectures to systematically benchmark predictive efficiencies across completely divergent climate profiles and environmental monitoring frameworks.

---

## 📂 Sub-Project Directory Structure

This core framework is divided into four distinct machine learning project architectures:

### 1. 📁 Transatlantic Air Quality Forecaster
*   **Description:** A macro-level combined project that integrates and flattens cross-continental pollution datasets from both Europe and the United States into a single multi-region operational data pipeline.
*   **Core Engineering:** Dynamic batch loading using `os.walk` to merge multi-file inputs, localized rolling memory buffers, and synchronized categorical indexing.
*   **ML Target:** Joint transatlantic predictive mapping utilizing competitive tree-based ensembles.

### 2. 📁 Europe Air Quality Forecaster
*   **Description:** An isolated regional forecasting engine specifically optimized for Mediterranean and European urban climates using high-resolution hourly datasets.
*   **Target Sites:** Athens (Greece), Ancona (Italy), and Zaragoza (Spain).
*   **Feature Focus:** Evaluates the co-dependencies of core regional gases (`NO2`, `O3`, `PM10`) and hyper-local meteorological data matrices (`Soil Temperature`, `Total Precipitation`).

### 3. 📁 US Metropolitan AQI Predictor
*   **Description:** A regional machine learning pipeline focused strictly on high-density American metropolitan setups to model close-proximity city sensor grids.
*   **Target Sites:** Sliced and filtered specifically for major US hubs like New York, Los Angeles, and Chicago.
*   **Feature Focus:** Heavy emphasis on diurnal human activity trends, structural lag features, and micro-variance indicators within high-traffic industrial zones.

### 4. 📁 Global Metropolitan AQI Predictor (50 Cities Bundle)
*   **Description:** An isolated global mega-scale forecasting pipeline trained simultaneously across 50 international cities over a massive telemetry data scope.
*   **Core Engineering:** High-cardinality nominal category mapping using specialized integer encodings and multi-hour moving standard deviation vectors.
*   **Feature Focus:** Benchmarks model generalization capabilities and limits tree overfitting under high-variance atmospheric volatility tracking, securing a peak validation threshold of **$R^2 = 0.6590$**.

---

## 🛠️ Unified Machine Learning Stack
*   **Language Environment:** Python 3.12+
*   **Algorithmic Engines:** XGBoost Regressor, Random Forest Regressor
*   **Analytics & Verification:** Pandas, NumPy, Scikit-Learn (Preprocessing & Metrics Modules)
*   **Visualization Suite:** Matplotlib, Seaborn (Custom Turbo, Mako, and Coolwarm Palette Mappings)

---

## 📂 Core Data Engineering Pipeline Implemented
1.  **Ingestion Sanitization:** Implemented an on-the-fly string transformation layer to automatically strip characters (`.`, `-`) and parse divergent source indexes into a unified `datetime` anchor to eliminate schema mismatch exceptions (`KeyError`).
2.  **Type-Safe Data Imputation:** Restricted data interpolation workflows (`ffill`/`bfill`) strictly within numeric sub-matrices (`df.select_dtypes(include=[np.number])`) to safely bypass mixed textual descriptors and prevent object conversion errors.
3.  **High-Cardinality Structural Encoding:** Utilized Sklearn's `LabelEncoder` to ingest complex global location tokens without inflating feature dimensions, bypassing memory allocation faults caused by traditional dummy variables across 50 cities.
4.  **Temporal Decomposition & Volatility Tracking:** Broken down continuous time elements into multi-variable indices (`Hour`, `DayOfWeek`, `Month`) and engineered 1-hour, 2-hour, and 24-hour historical lag structures paired with rolling standard deviations ($Rolling\_Std$) to capture rapid chronological pattern memory safely.
5.  **Temporal Leakage Prevention:** Applied strict sequential non-shuffled train-test boundary splits (80/20 Chronological Split) across all models to maintain operational time logic and simulate true real-world testing environments.

---

## 🚀 Execution & Setup Overview
Each sub-folder contains its own localized dataset structure and dedicated workspace notebook. To evaluate any specific setup:
1.  Navigate into the target sub-project directory (e.g., `cd "Global Metropolitan AQI Predictor"`).
2.  Ensure your dataset files are nested inside its respective `/data` folder.
3.  Launch the standalone Jupyter notebook found in the `/notebooks` directory to view the complete training curves, residual error frequency spreads, and comparative target forecast plots.
