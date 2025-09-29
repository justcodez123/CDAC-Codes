import { useState } from "react";

export default function Counter1()
{
   let [count , setcount]=useState(0)
   
 function Counter()
 {
   setcount(count+=1);  
   console.log(count)
 }
 return(

    <>
    
    <h1>Counter</h1>
    <h1>{count}</h1>
    <button onClick={Counter}>Counter 1</button>
    </>

 )



}