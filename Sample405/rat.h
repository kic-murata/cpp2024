#pragma once

class Rat {
public:
  Rat();  //コンストラクタ
  ~Rat(); //デストラクタ
  static void showNum();
  void squeak();
private:
  int m_id;
  inline static int s_count = 0;
};