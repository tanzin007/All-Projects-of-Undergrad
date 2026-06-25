# 🎬 Movie Review Sentiment Analysis using Fine-Tuned BERT

A professional Natural Language Processing (NLP) project that performs Binary Sentiment Classification (Positive/Negative) on the famous IMDb Movie Reviews Dataset. The core architecture utilizes a pre-trained **BERT-Base-Unscased** model as a feature extractor, with frozen base layers and a custom PyTorch Deep Neural Network head trained on Google Colab / Kaggle T4 GPUs.

---

## 📌 Project Overview
Training large Transformer models like BERT from scratch requires massive datasets and compute power. This project applies **Transfer Learning** using a feature extraction approach:
* **Base Model:** `bert-base-uncased` (Frozen to prevent overfitting and speed up training).
* **Custom Head:** A fully connected Feed-Forward Neural Network (`Linear -> ReLU -> Dropout -> Linear`).
* **Task:** Classifying raw text movie reviews into **Positive** or **Negative** sentiments.

---

## 📊 Dataset & Splitting
The project uses the standard **IMDb 50K Movie Reviews Dataset**. To ensure robust evaluation, the dataset is stratified and split into a **70% / 15% / 15%** ratio:

* 📦 **Total Labeled Records:** 50,000
* 🟢 **Train Set (70%):** 35,000 reviews (Used for optimizing the custom NN weights)
* 🟡 **Validation Set (15%):** 7,500 reviews (Used for epoch-wise performance checking)
* 🔴 **Test Set (15%):** 7,500 reviews (Holdout set kept completely unseen for final evaluation)

---

## 🛠️ System Architecture & Workflow

1. **Data Pipeline:** Local dataset loading via `kagglehub` or automated downloading pipelines.
2. **Text Tokenization:** Input texts are processed through `BertTokenizer` with padding, truncation, and a maximum sequence length of 128 tokens.
3. **Feature Extraction:** Tokenized inputs pass through the frozen BERT architecture to fetch the contextual embedding of the sentence representation token (`[CLS]`).
4. **Classification Head:** The 768-dimensional `[CLS]` token embedding is passed through our custom dense layers to output class probabilities.

---

## 🚀 Key Features
* **Hugging Face Style Progress Bars:** Customized native `tqdm` log outputs mimicking modern minimalist development aesthetics.
* **Stratified Splitting:** Prevents class imbalances across train/val/test data pipelines.
* **Resource Efficient:** Freezing BERT parameters makes the training extremely fast, requiring only 5 epochs to converge on a standard T4 GPU setup.

---

## 💻 Technical Stack
* **Language:** Python
* **Deep Learning Framework:** PyTorch (`torch`, `torch.nn`)
* **Transformer Library:** Hugging Face `transformers`
* **Data Processing & ML:** Pandas, NumPy, Scikit-Learn
* **UI Progress Logging:** tqdm

---

## 📈 Performance & Results
The model was trained for **5 Epochs** using the `AdamW` optimizer with a learning rate of `1e-3` and `CrossEntropyLoss`. 

### Final Evaluation Metrics:
* **Validation Accuracy:** 0.7699 (76.99%)
* **Final Holdout Test Accuracy:** 0.7775 (77.75%)

#### Classification Report (Unseen Data):
```text
              precision    recall  f1-score   support

    Negative       0.82      0.71      0.76      3750
    Positive       0.74      0.85      0.79      3750

    accuracy                           0.78      7500
   macro avg       0.78      0.78      0.78      7500
weighted avg       0.78      0.78      0.78      7500
```

---

## 🏃 How to Run the Notebook

1. Open a new notebook in **Google Colab** or **Kaggle**.
2. Enable GPU acceleration (**Runtime -> Change runtime type -> T4 GPU**).
3. Ensure the required libraries are installed:
   ```bash
   pip install torch transformers pandas scikit-learn tqdm kagglehub
   ```
4. Copy and paste the entire Python script into a code cell and execute.

---

## 📄 License
This project is open-source and available under the [MIT License](LICENSE).
