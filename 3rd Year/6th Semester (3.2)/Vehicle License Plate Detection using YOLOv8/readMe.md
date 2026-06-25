# 🚗 Automated Vehicle License Plate Detection using YOLOv8

A high-performance Computer Vision (CV) project developed on Google Colab using the **YOLOv8 (You Only Look Once)** architecture. The system is designed to localize and detect the exact spatial bounding box of vehicle license plates in real-time.

> ⚠️ **Important Project Scope Note:** This project focuses strictly on **Object Detection (Plate Localization)**. It identifies and draws a bounding box around the license plate on a vehicle, but does **NOT** perform Optical Character Recognition (OCR) to read the text or numbers written inside the plate.

---

## 📌 Project Overview
License plate localization is the critical first stage of any Intelligent Transportation System (ITS). This project applies transfer learning on a pre-trained **YOLOv8 Nano (yolov8n.pt)** model to build a highly efficient, lightweight, and fast detector capable of processing imagery on standard T4 cloud GPUs.

* **Core Task:** Single-Class Object Detection (`license_plate`).
* **Framework:** Ultralytics YOLOv8.
* **Inference Presentation:** Clean, centralized dashboard grid displaying localized specimen samples.

---

## 📊 Dataset & Configuration
The project utilizes the **Car Number Plate Dataset (YOLO Format)** by Sujay Mann, fetched directly via `kagglehub`.

* 📦 **Total Dataset Volume:** 433 curated vehicle images.
* 🟢 **Training Sub-set:** 346 images with bounding box coordinate labels.
* 🔴 **Validation/Testing Sub-set:** 87 holdout unseen verification images.
* 🛠️ **Data Pipeline:** Dynamically scanned root directories compiling a custom `dataset.yaml` for structural stability.

---

## 💻 Technical Stack
* **Language:** Python
* **Deep Learning Framework:** PyTorch (`torch`)
* **Computer Vision Suite:** Ultralytics YOLO, OpenCV (`cv2`)
* **Data Pipelines & Visuals:** Matplotlib, PyYAML, Glob, Kagglehub
* **Console UI:** tqdm (Hugging Face minimalist flat-green style)

---

## 🚀 Key Architectural Features
* **Dynamic Directory Mapping:** The preprocessing loop scans internal folders automatically to eliminate standard hardcoded `FileNotFoundError` bugs.
* **Premium Dashboard Grid:** Inference on unseen testing data is consolidated into a highly polished **3x3 visual gallery layout**, avoiding notebook scrolling clutter.
* **Minimalist Progress Logs:** Clean console tracking utilizing solid Unicode block formatting for real-time training analytics.

---

## 📈 Training Analytics & Results
The model was fine-tuned for **25 Epochs** with a standard image dimension scaling of `640x640` and an initial batch size of `16` using the `AdamW` optimizer.

### Performance Indicators (Holdout Set):
* **Training Time:** ~4 minutes (0.067 hours) on Tesla T4
* **Input Resolution:** 640x640 pixels
* **Precision (P):** 0.879 (87.9%)
* **Recall (R):** 0.862 (86.2%)
* **Final mAP50 Score:** 0.890 (89.0%)
* **Final mAP50-95 Score:** 0.527 (52.7%)


---

## 🏃 Setup & Execution Instructions

1. Open a new notebook instance in **Google Colab**.
2. Mount your accelerator hardware via **Runtime -> Change runtime type -> T4 GPU**.
3. Install the primary dependencies by executing:
   ```bash
   pip install ultralytics pandas matplotlib tqdm kagglehub pyyaml
   ```
4. Copy the complete pipeline script into a code block and run the cell to start automated execution.

---

## 📄 License
Distributed under the open-source [MIT License](LICENSE).
