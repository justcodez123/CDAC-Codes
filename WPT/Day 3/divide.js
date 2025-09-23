function divide(n1,n2){
     if (n2 === 0) {
        console.log("Error: Cannot divide by zero.");
        return ;
     }  

    console.log(`Division of two numers ${n1}, ${n2} is : ` + (n1/n2));
   
}
 divide(10,5);