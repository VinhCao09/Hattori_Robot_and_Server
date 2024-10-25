// API key và URL của API
const String API_KEY = "AIzaSyACCyV7E_9PKieweJPd0-J8WaK79emtKnM";
const String URL = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=" + API_KEY;

// Hàm gửi yêu cầu đến API và nhận kết quả
String askHattori(const String& prompt) {
  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(URL);

    http.addHeader("Content-Type", "application/json");

    // Tạo payload JSON
    String payload = "{\"contents\":[{\"role\": \"model\",\"parts\":[{\"text\": \"Bạn là một trợ lý, tên của bạn là Hattori, được phát triển bởi Cao Văn Vinh. Trả lời ngắn gọn không quá 200 từ, không sử dụng ký hiệu đặc biệt\"}]},{\"role\": \"user\",\"parts\":[{\"text\": \"" + prompt + "\"}]}]}";

    // Gửi yêu cầu POST
    int httpResponseCode = http.POST(payload);

    if (httpResponseCode > 0) {
      String response = http.getString();

      // Phân tích cú pháp JSON từ phản hồi
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, response);

      // Trả về nội dung phản hồi
      return doc["candidates"][0]["content"]["parts"][0]["text"].as<String>();
    } else {
      return "Error: " + String(httpResponseCode);
    }

    http.end();
  } else {
    return "Error: Not connected to WiFi";
  }
}