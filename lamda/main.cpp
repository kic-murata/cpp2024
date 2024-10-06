#include<iostream>
using namespace std;
int main() {
    int x = 0;
    int y = 10;

//    auto nc = []() { cout << x << ", " << y << endl; }; //�R���p�C���G���[
    auto nc = []() { cout << "NotCapture" << endl; };
    auto cc = [=]() { cout << x << ", " << y << endl; };      // �S�Ă��R�s�[�L���v�`��
    auto cr = [=, &y]() { cout << x << ", " << y << endl; };    // �f�t�H���g�R�s�[�Ay���Q�ƃL���v�`��
    auto rr = [&]() { cout << x << ", " << y << endl; };      // �S�Ă��Q�ƃL���v�`��

    cout << "nc()" << endl;
    nc();
    x = 1;
    y = 11;
    cout << "cc()" << endl;
    cc();   //0,10�@���̂Ƃ���x��cc���`�����Ƃ���x��y�̒l���R�s�[
    cout << "cr()" << endl;
    cr();   //0,11  ���̂Ƃ���x��cr���`�����Ƃ���x�Ay�͎Q�ƂȂ̂ōX�V���ꂽ11�ƂȂ�
    cout << "rr()" << endl;
    rr();   //1,11  x��y�Ƃ��ɎQ�ƂȂ̂ōŐV��x��y�̒l������

    [&x]() { x += 1; }();          // �Q�ƃL���v�`���͕ϐ��̕ύX���\
    //��L�̎��_��x�̒l��+1�����2�ɂȂ�
    //[y](){ y+=1; }();         // Copy�L���v�`���͕ϐ���ύX�s�\�iConst)
    [y]() mutable { y += 1; }();   // mutable�ɂ���ƕϐ��̕ύX���\�i�����R�s�[�Ȃ̂Ō��̕ϐ��͕s�ρj
    //�������y�͕������ꂽy��+1���邪�A����y�͕ύX����Ȃ�
    rr();   //2,11

    return 1;
}