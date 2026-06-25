# Email Spam & Phishing Classifier using NLP

A high-performance Natural Language Processing (NLP) and text classification framework designed to analyze corporate and consumer email strings, automatically filtering malicious phishing attempts and unsolicited spam text from legitimate communications.

## 📌 Project Overview
* **Problem Type:** Natural Language Processing (NLP) / Binary Text Classification
* **Dataset Scope:** 83,448 high-volume multi-source email blocks (TREC 2007 Public Spam Corpus + Enron Dataset combined).
* **Dataset Source:** Kaggle (`email-spam-classification-dataset` by purusinghvi)
* **Objective:** Standardize and tokenize unstructured linguistic configurations, engineer structural term weightings (TF-IDF), and train competitive Bayesian and regularized linear classifiers to maximize spam detection accuracy while reducing False Negatives (uncaught spam).

## 🛠️ Tech Stack & Core Libraries
* **Language Environment:** Python 3.12+
* **NLP Processing Libraries:** NLTK (Natural Language Toolkit)
* **Algorithmic Engines:** Multinomial Naive Bayes (MNB), Logistic Regression (LR)
* **Data Manipulation Stack:** Pandas, NumPy, Scikit-Learn (TfidfVectorizer)
* **Visualization Suite:** Matplotlib, Seaborn (Blues and Greens confusion matrix mappings)

## 📂 Advanced Engineering & NLP Pipeline
1. **Linguistic Ingestion Sanitization:** Stripped email header artifacts (`Subject:` markers), dropped tracking web hyper-links/URLs, eliminated numerical features/punctuation nodes using Regular Expressions (Regex), and forced absolute case unification (lowercasing).
2. **Stopwords Elimination:** Filtered transactional functional words (e.g., *'is'*, *'the'*, *'at'*) via NLTK corpus token constraints to keep text semantics high-density.
3. **Morphological Lemmatization:** Utilized NLTK's `WordNetLemmatizer` to contextually process terms back to their dictionary base states (e.g., *'running'*, *'runs'* $\rightarrow$ *'run'*), reducing matrix sparseness.
4. **TF-IDF Feature Construction:** Implemented token frequency metrics combined with inverse document properties (`ngram_range=(1, 2)`) to extract the 5,000 most significant unigrams and bigrams as structural predictive inputs.
5. **Stratified Data Balancing Partition:** Applied an 80/20 train-test ratio splitting with stratification (`stratify=y`) to secure identical positive/negative class distributions across training and validation testing environments.

## 📈 Final Model Performance Metrics

The algorithms were benchmarked across a massive validation set of 16,690 emails, yielding enterprise-grade text classification matrices:

| Predictive NLP Classifier Engine | Overall Validation Accuracy | Precision (Spam) | Recall (Spam) | F1-Score |
| :--- | :---: | :---: | :---: | :---: |
| **Logistic Regression (LR)** | **98.29%** | **0.98** | **0.99** | **0.98** |
| Multinomial Naive Bayes (MNB) | 96.72% | 0.97 | 0.97 | 0.97 |

### Advanced Modeling Insights
The regularized **Logistic Regression** framework marginally outperformed the probabilistic Multinomial Naive Bayes model across all testing weights. Securing a **99% Recall for Spam** proves that the combination of custom TF-IDF n-grams ($1, 2$) and Lemmatization effectively isolates sophisticated phishing vocabulary patterns with a near-zero rate of false clearance, ensuring highly robust network security routing.

## 📊 Visualized Analytical Insights
* **Balanced Class Distribution:** Countplot diagnostics show an ideal distribution (~52.6% Spam vs ~47.3% Ham), preventing the model from becoming biased toward any specific class.
* **Tight Error Boundaries:** Comparative subplots of confusion matrices reveal that Logistic Regression only misclassified a minimal number of spam emails, optimizing real-world deployability.

## 🚀 Local Execution Blueprint
1. Clone this repository and navigate to the isolated project directory:
   ```bash
   cd "Email Spam & Phishing Classifier"
   ```
2. Place the raw `combined_data.csv` file inside the `/data` folder.
3. Launch the standalone Jupyter file to review the underlying text transformations, model token vocabularies, and confusion subplots layouts:
   ```bash
   jupyter notebook notebooks/*.ipynb
   ```
