#pragma once

class Rat {
public:
  Rat();  //�R���X�g���N�^
  ~Rat(); //�f�X�g���N�^
  static void showNum();
  void squeak();
private:
  int m_id;
  static int s_count;
};