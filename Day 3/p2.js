/*Write a Program to use Different Array Library Functions
 using switch case*/

 function usefun(ch) {
    let arr = [12, 23, 0, 89, 55];
    switch(ch){
        case "map":
            // The .map() method creates a new array by applying a function to 
            // each element.
            // Here, we'll create a new array where each element is doubled.
            const doubledArr = arr.map(element => element * 2);
            console.log("Array with each element doubled:", doubledArr);
            break;
        case "foreach":
            largest = arr[0];
            arr.forEach((ele) => {largest < ele ? largest = ele : largest})
            console.log("largest element in the arr:"+largest);
            break;
        case "filter":
            //Here we save no.s greater than 5 in new a2
            const newa2 = arr.filter((e) => e > 5 );
            console.log("No.s greater than 5" + newa2);
            break;
        case "sort" :
            arr.sort((a,b) => a-b);
            console.log("Sorted in increasing order:" + arr);
            arr.sort((a,b) => {b-a});
            console.log("Sorted in Decreasing order:" + arr);
            break;
    }
 }

 usefun("foreach");


