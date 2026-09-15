import java.util.*;

public class Solution {
    Map<String, Integer> steps = new HashMap<>();
    List<List<String>> result = new ArrayList<>();
    List<String> path = new ArrayList<>();
    String bWord;

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> dict = new HashSet<>(wordList);
        if (!dict.contains(endWord)) {
            return result;
        }

        bWord = beginWord;
        
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        steps.put(beginWord, 0);

        while (!queue.isEmpty()) {
            String word = queue.poll();
            int step = steps.get(word);

            if (word.equals(endWord)) break;

            char[] chars = word.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                char original = chars[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (chars[i] == c) continue;
                    chars[i] = c;
                    String newWord = new String(chars);

                    if (dict.contains(newWord)) {
                        if (!steps.containsKey(newWord)) {
                            steps.put(newWord, step + 1);
                            queue.add(newWord);
                        }
                    }
                }
                chars[i] = original;
            }
        }

        if (steps.containsKey(endWord)) {
            path.add(endWord);
            dfs(endWord);
        }

        return result;
    }

    private void dfs(String word) {
        if (word.equals(bWord)) {
            List<String> copy = new ArrayList<>(path);
            Collections.reverse(copy);
            result.add(copy);
            return;
        }

        int currentStep = steps.get(word);
        char[] chars = word.toCharArray();

        for (int i = 0; i < chars.length; i++) {
            char original = chars[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (chars[i] == c) continue;
                chars[i] = c;
                String prevWord = new String(chars);

                if (steps.containsKey(prevWord) && steps.get(prevWord) == currentStep - 1) {
                    path.add(prevWord);
                    dfs(prevWord);
                    path.remove(path.size() - 1);
                }
            }
            chars[i] = original;
        }
    }
}