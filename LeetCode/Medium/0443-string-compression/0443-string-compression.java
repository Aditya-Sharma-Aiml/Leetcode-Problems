class Solution {
    public int compress(char[] chars) {

        int n = chars.length;
        int idx=0;

        for(int i=0; i<n;              ){

            char curr = chars[i];
            int count = 0;

            while(i<n && chars[i]==curr){
                count++;
                i++;
            }

            chars[idx++] = curr;

            if(count > 1){
                // String countStr = String.valueOf(count);
                String countStr = Integer.toString(count);

                for(char ch : countStr.toCharArray()){
                    chars[idx++] = ch;
                }
            }
        }
        return idx;
    }
}