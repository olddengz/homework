//#include "resource.h"
//#include "check_legal.h"
//#include "greedy.h"
//#include "lines_delet.h"
//#include "place_and_end.h"
//#include "rand.h"
//
//int main() {
//    char s0, s1, si;
//    int shape_map[256]; // 字符到形状索引的映射（I=0, T=1, O=2,...）
//    // 初始化形状映射表...
//
//    // 读取前两个方块
//    s0 = rand();
//    s1 = rand();
//    int current_shape = shape_map[s0];
//    int next_shape = shape_map[s1];
//
//    while (1) {
//        // 寻找最优放置方案
//        smart_decide(current_shape, next_shape);
//
//        // 输出结果（注意角度为0/90/180/270，实际c为旋转次数×90°）
//        printf("%d %d\n%d\n", best_c * 90, best_x, total_score);
//        fflush(stdout); // 必须刷新缓冲区
//
//        // 读取下一个方块
//        scanf(" %c", &si);
//        if (si == 'X') { // 处理最后一个方块后结束
//            break;
//        }
//        else if (si == 'E') { // 游戏结束
//            return 0;
//        }
//        else {
//            // 更新当前和下一方块
//            current_shape = next_shape;
//            next_shape = shape_map[si];
//        }
//    }
//    return 0;
//}