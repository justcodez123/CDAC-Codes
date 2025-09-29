import { useEffect, useState, useRef} from "react";

export default function Counter2()
{
 let [count, setcount]=useState(0); 

 function Count(){    
      setcount(count+=1);
      console.log("from function "+ count );
 }

 useEffect(()=>{
    console.log("from use "+ count);
   },[Count]);

  const tableRows = [];
  for (let i = 1; i <= 10; i++) {
    tableRows.push(
      <tr key={i}>
        <td>{count} x {i}</td>
        <td>=</td>
        <td>{count * i}</td>
      </tr>
    );
  }
   
   
 return(

    <>
    <h1>Counter 2</h1>
    <h1>{count}</h1>
    <button onClick={Count}>Counter 2</button>
    <h1>Table</h1>
    <br/>
    <table border={2} align="center" color="red">
        {tableRows}
    </table>
    </>

 )

}