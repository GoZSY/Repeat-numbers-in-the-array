方法一：额外的数组，计算每个数字出现的次数
public class Solution {
    public boolean duplicate(int numbers[],int length,int [] duplication) {
        int[] array = new int[length];
        for (int i=0;i<length;i++) {
            array[numbers[i]]++;
        }
        for (int i=0;i<length;i++) {
            if (array[i]>1) {
                duplication[0] = i;
                return true;
            }
        }
        return false;
    }
     
}
方法二、分析知，如果没有重复则数组每一个元素值就等于其下标值，有重复则会有例外。那么我们遍历每个元素时，
对比元素值和下标，如果相同则继续遍历，如果不同则对比数组中下标为元素值的的元素，相同则结束遍历，不同则进行交换。
持续此过程直到出现重复值。
public boolean duplicate(int numbers[],int length,int [] duplication) {
        if(numbers == null || numbers.length != length || length <= 0){
            return false;
        }
 
        for(int i = 0; i < length; i++){
            if(numbers[i] < 0 || numbers[i] >= length){
                return false;
            }
             
            while(numbers[i] != i){
                if(numbers[numbers[i]] == numbers[i]){
                    duplication[0] = numbers[i];
                    return true;
                }else{
                    swap(numbers, i, numbers[i]);
                }
            }
        }
        return false;
    }
     
    public void swap(int[] numbers, int x, int y){
        int tmp = numbers[x];
        numbers[x] = numbers[y];
        numbers[y] = tmp;
    }
方法三、 将数组中值看作索引，两个相同的值会去更新同一个索引值，
去更新索引值的时候检查一下数值是否大于数组的长度，如果大于，
表示已经有索引更新过这个值，那么当前索引也就是重复的。
public boolean duplicate(int numbers[],int length,int [] duplication) 
{
    if(numbers == null || numbers.length != length || length <= 0)
    {
      return false;
    }
    for(int i = 0 ; i < length; i++) 
    { 
      int index = numbers[i]; 
      if(numbers[index % length] >= length)
        {
            duplication[0] = index % length; 
            return true;
        } 
      else 
        {
            numbers[index % length] += length;
        }
    } 
    return false;
}
