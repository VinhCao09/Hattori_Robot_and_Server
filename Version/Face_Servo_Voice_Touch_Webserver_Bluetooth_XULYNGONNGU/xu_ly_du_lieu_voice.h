// Hàm tính khoảng cách Levenshtein giữa hai chuỗi
int levenshteinDistance(const String &s1, const String &s2) {
    const size_t len1 = s1.length(), len2 = s2.length();
    int d[len1 + 1][len2 + 1];

    for (size_t i = 0; i <= len1; i++) d[i][0] = i;
    for (size_t j = 0; j <= len2; j++) d[0][j] = j;

    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            d[i][j] = std::min({d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1)});
        }
    }

    return d[len1][len2];
}

// Hàm chuẩn hóa chuỗi
String normalizeMessage(String message) {
    message.toLowerCase();
    message.trim();
    return message;
}

// Hàm so sánh chuỗi gần đúng
String getClosestCommand(const String &message, const String commandList[], int commandCount, double threshold = 0.6) {
    String closestMatch = "";
    int minDistance = INT_MAX;

    for (int i = 0; i < commandCount; i++) {
        int distance = levenshteinDistance(normalizeMessage(message), normalizeMessage(commandList[i]));
        if (distance < minDistance) {
            minDistance = distance;
            closestMatch = commandList[i];
        }
    }

    double similarity = 1.0 - (double)minDistance / std::max(message.length(), closestMatch.length());
    return similarity >= threshold ? closestMatch : "";
}

String pre_message = "";
int pre_lenh;
int handleMessage(String message) {
    String commandList[] = {
        "tắt đèn đỏ", "tắt máy lạnh", "bật máy lạnh", "bật đèn đỏ",
        "bật máy quạt", "tắt máy quạt", "bạn được phát triển bởi ai", 
        "xin chào", "chào bạn","i love you","tôi yêu bạn","hey hatori", "ok hatori", "bật rơ le", "tắt rơ le", "bật nhạc anh tuấn cùi", "lên nhạc anh tuấn cùi"
    };
    int commandCodes[] = {9, 8, 11, 10, 13, 12, 2, 16, 16, 15, 15, 16, 16, 17, 18, 19, 19};
    int commandCount = sizeof(commandList) / sizeof(commandList[0]);

    if (normalizeMessage(message) != normalizeMessage(pre_message)) {
        String command = getClosestCommand(message, commandList, commandCount);
        if (command != "") {
            int commandIndex = std::distance(commandList, std::find(commandList, commandList + commandCount, command));
            myDFPlayer.play(commandCodes[commandIndex]);
            lenh=commandCodes[commandIndex];
        }
        else {
            myDFPlayer.play(6);  // Phát nhạc vị trí số 6 nếu không có lệnh nào gần đúng
        }
                pre_message = message;
                
    }
    return lenh;
}
void DIEUKHIENTHIETBI(int lenh) {
    if (lenh == 17&&pre_lenh!=17) {
        digitalWrite(LED, HIGH); pre_lenh=lenh;
    } 
    if (lenh == 18&&pre_lenh!=18) {
        digitalWrite(LED, LOW); pre_lenh=lenh;
    }

    if (lenh == 15&&pre_lenh!=15)
    {
        display.clearDisplay();
        display.drawBitmap(0, 0, heart, 128, 64, 1);
        display.display();
        delay(6000); pre_lenh=lenh;
    }
}