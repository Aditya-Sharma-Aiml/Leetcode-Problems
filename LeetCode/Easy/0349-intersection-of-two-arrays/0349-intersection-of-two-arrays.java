class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        if(m<n) return intersection(nums2, nums1);
        Set<Integer> ans = new HashSet<>();
            

        int[] visited = new int[n+m];
        // Arrays.fill(visited, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i]==nums2[j] && visited[j] == 0){
                    ans.add(nums1[i]);
                    visited[j]=1;
                    break;
                }
        
            }
        }
        int[] arr = new int[ans.size()];
        int i=0;
        for (int x: ans) {
            arr[i++] = x;
        }
        return arr;
    }
}