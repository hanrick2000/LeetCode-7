查找第一个   >= target 的插入位置：
    int search(vector<int> &v, int target) {

        int p = 0, q = int(v.size())-1;
        
        while(p < q) {
            
            int c = (q-p)/2+p;
            
            if(v[c] < target) {
                p = c+1;
            }
            
            else {
                q = c;
            }
        }

        return v[p] >= target? p: p+1;  //一定要判断的，因为你不确定数组里面到底有没有满足条件的，p永远都只是一个candidate角色
        
    }

查找第一个 < target的插入位置:
    
    int search(vector<int> &v, int target) {

        int p = 0, q = int(v.size())-1;
        
        while(p < q) {
            
            int c = (q-p-1)/2 + p+1;
            
            if(v[c] >= target) {
                q = c - 1;
            }
            
            else {
                p = c;
            }
        }
        
        return v[p]<target?p+1:p;
        
    }

