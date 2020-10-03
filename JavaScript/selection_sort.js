function selectionSort(arr){

    var minIndex, temp, len = arr.length

    for(var i = 0; i < len; i++){
        
        minIndex = i

      for(var  j = i+1; j<len; j++){
         if(arr[j]<arr[minIndex]){
            minIndex = j
         }
      }

      temp = arr[i]
      arr[i] = arr[minIndex]
      arr[minIndex] = temp
    }

    
    return arr;
  }