//#include "resource.h"
//#include "check_legal.h"
//#include "greedy.h"
//#include "lines_delet.h"
//#include "place_and_end.h"
//#include "rand.h"
//
//int main() {
//    char s0, s1, si;
//    int shape_map[256]; // �ַ�����״������ӳ�䣨I=0, T=1, O=2,...��
//    // ��ʼ����״ӳ���...
//
//    // ��ȡǰ��������
//    s0 = rand();
//    s1 = rand();
//    int current_shape = shape_map[s0];
//    int next_shape = shape_map[s1];
//
//    while (1) {
//        // Ѱ�����ŷ��÷���
//        smart_decide(current_shape, next_shape);
//
//        // ��������ע��Ƕ�Ϊ0/90/180/270��ʵ��cΪ��ת������90�㣩
//        printf("%d %d\n%d\n", best_c * 90, best_x, total_score);
//        fflush(stdout); // ����ˢ�»�����
//
//        // ��ȡ��һ������
//        scanf(" %c", &si);
//        if (si == 'X') { // �������һ����������
//            break;
//        }
//        else if (si == 'E') { // ��Ϸ����
//            return 0;
//        }
//        else {
//            // ���µ�ǰ����һ����
//            current_shape = next_shape;
//            next_shape = shape_map[si];
//        }
//    }
//    return 0;
//}