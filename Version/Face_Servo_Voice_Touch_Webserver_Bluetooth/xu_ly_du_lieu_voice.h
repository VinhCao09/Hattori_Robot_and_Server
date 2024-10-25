void XULYDATA(String message1)
{
     if (message1=="Tắt đèn đỏ"||message1=="tắt đèn đỏ"&&pre_message!=message1) 
      {
        myDFPlayer.play(9); pre_message=message1; 
      }
      if (message1=="Tắt máy lạnh"||message1=="tắt máy lạnh"&&pre_message!=message1) 
      {
        myDFPlayer.play(8); pre_message=message1;
      }
      if (message1=="Bật máy lạnh"||message1=="bật máy lạnh"&&pre_message!=message1) 
      {
        myDFPlayer.play(11); pre_message=message1;
      }
       if (message1=="Bật đèn đỏ"||message1=="bật đèn đỏ"&&pre_message!=message1) 
      {
        myDFPlayer.play(10); pre_message=message1;
      }
      if (message1=="Bật máy quạt"||message1=="bật máy quạt"&&pre_message!=message1) 
      {
        myDFPlayer.play(13); pre_message=message1;
      }
      if (message1=="Tắt máy quạt"||message1=="tắt máy quạt"&&pre_message!=message1) 
      {
        myDFPlayer.play(12); pre_message=message1;
      }
       if (message1=="Bạn được phát triển bởi ai"||message1=="bạn được phát triển bởi ai"&&pre_message!=message1) 
      {
        myDFPlayer.play(2); pre_message=message1;
      }
      if (message1=="xin chào"||message1=="Xin chào"||message1=="chào bạn"||message1=="Chào bạn"&&pre_message!=message1) 
      {
        myDFPlayer.play(1); pre_message=message1;
      }
       if (message1=="tôi yêu bạn"||message1=="Tôi yêu bạn"||message1=="i love you"||message1=="I love you"||message1=="làm hình trái tim tỏ tình crush"||message1=="Làm hình trái tim tỏ tình crush"&&pre_message!=message1) 
      {
                // Clear the buffer.
        display.clearDisplay();
      // Draw W01 WORD_HELLO bitmap on the screen
        display.drawBitmap(0, 0, heart, 128, 64, 1);
        display.display();

        myDFPlayer.play(15); pre_message=message1;
        delay(1500);
      }
}