//7) To Find max number from array write code in 3 ways as shown in lecture 

 var a = [500, 100 , 200, 900, 50];
 max=a[0];
 a.forEach((element) => {
      element > max ?  max = element : a[0];
 });
console.log(max);

   
for(const j in a){
    if(j > max)
        max = j;
}
console.log(max)

for (i=0;i<=a.length;i++)
    {
        if(max<a[i])
        {
           max=a[i]; 
        }
    }

 console.log(max)   
