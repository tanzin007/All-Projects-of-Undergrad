# Customer Segmentation using K-Means Clustering

An unsupervised machine learning project to segment retail shop customers into distinct groups based on their annual income and spending behaviors.

## 📌 Project Overview
* **Problem Type:** Unsupervised Learning (Clustering)
* **Objective:** Group customers to help the marketing team design targeted strategies.
* **Dataset source:** Kaggle (Mall Customer Segmentation Data)

## 🛠️ Tech Stack
* Python, Pandas, NumPy, Scikit-Learn (KMeans), Matplotlib, Seaborn

## 📂 Methodology & Workflow
1. **Exploratory Data Analysis (EDA):** Visualized distribution of Age, Annual Income, and Spending Score. Checked for missing values.
2. **Feature Selection:** Selected `Annual Income` and `Spending Score` as the primary features for 2D clustering.
3. **Finding Optimal Clusters:** Used the **Elbow Method** (WCSS - Within-Cluster Sum of Squares) to determine the ideal number of clusters.
4. **Model Training:** Trained the K-Means algorithm with the optimal cluster count.
5. **Visualization:** Plotted the final clusters along with their respective centroids.

## 📊 Key Insights & Segments
Through this clustering analysis, customers were divided into distinct groups:
* **Target Group:** High Income, High Spending Score (Ideal for premium product marketing).
* **Careful Group:** High Income, Low Spending Score.
* **Spendthrifts:** Low Income, High Spending Score.
