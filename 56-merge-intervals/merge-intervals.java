class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length <= 1){
            return intervals;
        }
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> result = new ArrayList<>();

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int[] interv : intervals){
            if(interv[0] <= end){
                end = Math.max(end, interv[1]);
            }
            else{
                result.add(new int[]{start, end});
                start = interv[0];
                end = interv[1];
            }
        }
        result.add(new int[]{start, end});
        return result.toArray(new int[0][]);
    }
}