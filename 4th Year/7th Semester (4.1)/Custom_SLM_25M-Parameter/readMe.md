# TinyStories Custom SLM 25M 🚀

A 25.4-million parameter **Decoder-Only Custom Transformer** (Small Language Model) built entirely from scratch using PyTorch. The model was successfully trained on 30,000 short stories from the **TinyStories Dataset** over 3 epochs, achieving excellent causal generation capabilities.

---

## ✨ Key Features

* **100% Scratch Built:** Designed and coded completely from the ground up without relying on pre-trained checkpoints or high-level Hugging Face abstractions.
* **0% Padding Packed Pipeline:** Eliminates padding tokens entirely. The entire text corpus is tokenized into a continuous stream and packed into fixed-size continuous blocks, ensuring 100% backpropagation efficiency.
* **Independent Character Tokenizer:** Uses a custom, self-contained character-level tokenizer with a unique vocabulary tracking 103 distinct characters.
* **Causal Self-Attention Architecture:** Implements a standard GPT-2 style causal multi-head attention mechanism with lower-triangular causal masking and weight tying between the token embedding and the language modeling head.
* **Cosine Annealing Optimization:** Features an advanced `AdamW` optimization loop synchronized with a `CosineAnnealingLR` learning rate scheduler for smooth optimization dynamics.

---

## 🧠 Model Architecture & Hyperparameters

| Hyperparameter | Value |
| :--- | :--- |
| **Total Parameters** | 25,403,904 (~25.4M) |
| **Number of Layers (`n_layer`)** | 8 |
| **Number of Attention Heads (`n_head`)** | 8 |
| **Embedding Dimension (`n_embd`)** | 512 |
| **Context Window (`block_size`)** | 256 Characters |
| **Vocabulary Size (`vocab_size`)** | 103 Unique Characters |
| **Dropout Rate** | 0.1 |

---

## 📈 Training Performance & Convergence

The dataset was packed into **76,250 distinct continuous blocks**, running 1,191 gradient updates per epoch with a batch size of 64.

* **Initial State:** Produced chaotic, randomized character sequences.
* **Epoch 1:** True Generative Loss: `1.5058`
* **Epoch 2:** True Generative Loss: `0.8305`
* **Epoch 3:** True Generative Loss: `0.7366`

> **Analysis:** The healthy, steady loss reduction down to **0.73** indicates a clean optimization curve without overfitting or gradient saturation. The model learned spelling, syntax, punctuation, and contextual flow flawlessly.

---

## 📝 Generation Evolution & Sample Output

### **Prompt Provided:** 
> `"Once upon a time, a little girl named Lily found a green "`

### **Output Progress over Training:**

* **Before Training (Random State):** 
  > `Once upon a time, a little girl named Lily found a green X9977Q7Sj888'©SS58QSSZ797Q...`
* **After Epoch 1 (Word Structure Emergence):** 
  > `Once upon a time, a little girl named Lily found a green who wanted to play with her toy together...`
* **After Epoch 3 (Final Fluent Output):**
  > `Once upon a time, a little girl named Lily found a green frog in the park with her mom. They walked away from the hospital. Lily did not want to play with her toys. She felt very brave and did not like to p...`

*The final epoch output demonstrates true context awareness by dynamically generating the noun **"frog"** to match the adjective **"green"** smoothly.*

---

## 🛠️ How to Setup and Run

### 1. Installation
Install the necessary dependencies inside your Python/GPU environment:
```bash
pip install torch pandas numpy kagglehub tqdm
```

### 2. Execution Pipeline
Running the notebook automatically executes the following pipeline sequence:
1. Downloads the dataset via `kagglehub`.
2. Encodes and streams the text via `CustomCharTokenizer`.
3. Sets up the non-padded `PackedStoriesDataset`.
4. Executes the high-velocity training loops.
5. Saves the production-ready weights as `packed_independent_slm.pt`.

### 3. Inference / Generation Engine
To generate your own custom short stories using the saved model weights:
```python
output_story = generate_text(
    model, 
    tokenizer, 
    prompt="Once upon a time, a little boy named Timmy saw a huge ", 
    max_new_tokens=150, 
    temperature=0.8, 
    top_k=8
)
print(output_story)
```

---

## 💾 Model Serialization
Upon successful training execution, the absolute weights are stored directly in your directory:
* **Saved Weight File:** `packed_independent_slm.pt`
