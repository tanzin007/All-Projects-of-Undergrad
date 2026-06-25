# 🤖 AI-Powered Line Following Waiter Robot (Kaggle Production Edition)

An interactive machine learning decision engine that emulates hardware outputs, state-machine overrides, and hardware triggers for an autonomous **Line-Following Waiter Robot** using a trained Random Forest model.

---

## 🚀 Emulated Arduino State Machine Workflow

This machine learning framework maps sensor configurations directly to simulate an embedded C++ architecture operating across these cycles:
- **`WAIT_INPUT`:** System holds until a valid table destination target (`1-5`) is input via the 2x3 keypad grid.
- **`GO_TO_TABLE`:** Evaluates dual Infrared parameters (`Left IR` and `Right IR`) to maintain line balance while checking the node threshold criteria.
- **`DELIVER`:** Pauses the dual L298N wheel motor drives to flash safety RGB codes during food-serving logs.
- **`RETURNING`:** Inverts tracking loops to route the robot back securely into the kitchen hub.
- **Obstacle Intervention:** An ultrasonic sensor loop overrides ongoing processes to trigger an emergency braking event whenever a block is flagged at a distance of **`<= 7 cm`**.

---

## 📊 Kaggle Deployment & Dataset Instructions

To keep this repository lightweight, the raw structural hardware telemetry data logs are omitted from this repository. Follow these procedures to run the workflow on Kaggle:

1. **Deploying the Notebook:** Open the [Kaggle Code Workspace](https://kaggle.com), select **"New Notebook"**, then click `File -> Upload Notebook` to attach the `.ipynb` file from this project.
2. **Attaching Data Input:** On the right-hand configurations column of your Kaggle notebook, click **"Add Data"**. Upload your custom comma-separated robot logs (`.csv`) containing the necessary column matrices.
3. **Map Kaggle Pathing Variables:** Paste your newly generated Kaggle directory source path inside the empty string parameter in Section 1:
   ```python
   robot_data_path = "/kaggle/input/your-dataset-name/robot_data.csv"
   ```

---

## ⚙️ How to Setup & Run locally in VS Code

If you choose to run the script inside your local desktop environment:

1. Clone this project folder repository structure and access it within VS Code.
2. Install the necessary system dependencies via terminal:
   ```bash
   pip install numpy pandas scikit-learn gradio
   ```
3. Attach your dataset path locally inside the empty `robot_data_path` variable.
4. Launch your Jupyter environment and click **"Run All"** to trigger the model and spin up the live shareable Gradio dashboard URL interface.
