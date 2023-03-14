//小A字符串异或
// import java.util.ArrayList;

// public class XORLinearBasis {
    
//     public static void insert(ArrayList<Integer> B, int x) {
//         for (int y : B) {
//             if (x >> Integer.numberOfTrailingZeros(y) == y) {
//                 return;
//             }
//             x ^= y;
//         }
//         B.add(x);
//     }
    
//     public static int solve(int[] s) {
//         ArrayList<Integer> B = new ArrayList<Integer>();
//         for (int x : s) {
//             insert(B, x);
//         }
//         return B.size();
//     }
    
//     public static void main(String[] args) {
//         int[] s = {0b110, 0b1010, 0b1111, 0b11000, 0b101011};
//         System.out.println(solve(s));  // 输出2
//     }
// }
//删除游戏
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class ScoreMaximization {
    
    public static int maxScore(int[] a) {
        Arrays.sort(a);  // 对a进行排序
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();  // 记录每个数的出现次数
        for (int x : a) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        int ans = 0;  // 记录总分数
        for (int x : a) {
            if (map.containsKey(x)) {
                ans += x;  // 累加x的分数
                map.remove(x);
                map.remove(x - 1);
                map.remove(x + 1);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] a = {1, 2, 3, 3, 3, 4, 5, 5};
        System.out.println(maxScore(a));  // 输出16
    }
}

