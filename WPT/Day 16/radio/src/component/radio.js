import React from "react"
import { useState } from "react";
    
const Radio = () => {

    let [userValue, onChange] = useState(" ");
    
    function accept(e) {
         onChange(e.target.value);
    }

    function handleU() {
        onChange(userValue.toUpperCase());
    }

    function handleL() {
        onChange(userValue.toLowerCase());
       
    }

    function handleT() {
          let titleCase =  userValue
         .toLowerCase().split()
         .map((w) => w.charAt(0).toUpperCase()+ w.slice(1))
         .join(" ");
         onChange(titleCase);
    }

    return(
        <> 
           <br></br>
            <input
             type = "text"
             placeholder 
             onChange={accept}
            />
            <br/>
            <label >
                <input
                 type="radio"
                 name="select" 
                 onClick={handleU}
                />uppercase
            </label>
            <br/>
            <label >
                <input
                 type="radio"
                 name="select"
                 onClick={handleL}
                />
                    lowerCase
                
            </label>
            <br/>
            <label>
                <input
                 type="radio"
                 name="select"
                 onClick={handleT}
                />titleCase
                
            </label>
            <br/>
            <label>
                <h3> {userValue} </h3>
            </label>
        </>
    )
}

export default Radio;