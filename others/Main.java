import java.util.HashSet;
import java.util.Set;
// a b a b c d e d e
// 0 1 2 3 4 5 6 7 8 9
public class Main {
    public static int uniqueSubstrings(String input) {
        int i = 0, ans = 1, start = 0;
        Set<Character> set = new HashSet<>();

        while (i < input.length()) {
            if (set.contains(input.charAt(i))) {
                
                System.out.println("i: " + i + " start: " + start + " ans: " + ans + " set: " + set);
                ans = Math.max(i - start, ans);
                while (start <= i && input.charAt(start) != input.charAt(i)) {
                    set.remove(input.charAt(start));
                    start++;
                }
                if (start <= i) {
                    start++;
                }
                i++;
            } else {
                set.add(input.charAt(i));
                i++;
            }
        }

        // Check if the last unique substring is the longest
        ans = Math.max(i - start, ans);
        set.clear();

        return ans;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String input = "ababcdede";

        int result = uniqueSubstrings(input);

        System.out.println("Length of the longest substring without repeating characters: " + result);
    }
}
