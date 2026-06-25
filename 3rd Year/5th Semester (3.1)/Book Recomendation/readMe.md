# 📚 Smart Book Recommendation System (Kaggle Production Edition)

An interactive machine learning-powered book recommendation engine built using **Item-Based Collaborative Filtering** and **Cosine Similarity** via a Gradio Web Interface. 

---

## 🚀 Kaggle Workflow & Machine Learning Architecture

- **Kaggle Pipeline Optimization:** Engineered to handle and process large-scale reading matrices directly within Kaggle's high-memory compute environments.
- **High-Fidelity Data Profiling:** Filters out massive real-world data noise by isolating expert reviewers (users with >200 ratings) and mainstream books (minimum 50 ratings).
- **Mathematical Cosine Vectoring:** Converts the preprocessed user-item matrices into high-dimensional space to compute exact similarity weights using Scikit-Learn's `cosine_similarity`.

---

## 🛠️ Data Science Tech Stack

- **Platform Environment:** Kaggle Notebook / Jupyter Notebook (`.ipynb`)
- **Data Engineering:** Python, Pandas, NumPy
- **Machine Learning Core:** Scikit-Learn (`cosine_similarity`)
- **Web UI Engine:** Gradio Framework
- **Dataset Source:** [Book Recommendation Dataset by Arashnic on Kaggle](https://kaggle.com)

---

## ⚙️ How to Run Directly on Kaggle (No Local Download Needed)

Since this project is optimized for Kaggle, you can run the entire model instantly without downloading any massive datasets to your local PC:

1. **Upload Notebook to Kaggle:** Go to [Kaggle Notebooks](https://kaggle.com), click on **"New Notebook"**, then go to `File -> Upload Notebook` and upload the `.ipynb` file from this repository.
2. **Add the Dataset:** On the right-hand panel of your Kaggle notebook, click on **"Add Data"** or **"Input"**. Search for **"Book Recommendation Dataset"** by `arashnic` and click add.
3. **Configure Dataset Paths:** Update the first section of the notebook with Kaggle's internal input paths:
   ```python
   books_path = "/kaggle/input/book-recommendation-dataset/Books.csv"
   ratings_path = "/kaggle/input/book-recommendation-dataset/Ratings.csv"
   users_path = "/kaggle/input/book-recommendation-dataset/Users.csv"
   ```
4. **Run the Model:** Click **"Run All"**. The notebook will automatically install `gradio`, process the matrix, and generate a **live shareable public link** to open the web dashboard interface.

---

## 💻 How to Run Locally in VS Code

If you prefer to download the data and run it on your local machine:

1. **Download the Dataset:** Download and unzip the official **[Book Recommendation Dataset](https://kaggle.com)** from Kaggle.
2. **Configure Local Project Paths:** Place `Books.csv`, `Ratings.csv`, and `Users.csv` into a folder on your PC. Open the `.ipynb` file in VS Code and fill in your exact local directory paths:
   ```python
   books_path = "path/to/your/Books.csv"
   ratings_path = "path/to/your/Ratings.csv"
   users_path = "path/to/your/Users.csv"
   ```
3. **Install Dependencies:** Open your VS Code terminal and install the required modules:
   ```bash
   pip install numpy pandas scikit-learn gradio
   ```
4. **Execute Notebook:** Click **"Run All"** inside your VS Code Jupyter environment to launch the Gradio UI dashboard.
