import { useState } from 'react';

export default function DataList() {
  const [inputValue, setInputValue] = useState('');
  
  const [itemList, setItemList] = useState([]);

  const handleInputChange = (event) => {
    setInputValue(event.target.value);
  };

  const handleBlur = () => {
    if (inputValue.trim() !== '') {
      setItemList([...itemList, inputValue]);
      
      setInputValue('');
    }
  };

  return (
    <div>
      <h2>Enter Items for Your List</h2>
      <label htmlFor="dataInput">New Item: </label>
     
      <input
        type="text"
        id="dataInput"
        value={inputValue}
        onChange={handleInputChange}
        //onBlur={handleBlur}
        placeholder="Type here and click away..."
      
      />
       <button onClick={handleBlur} >Submit</button>
      <hr />

      <h3>Your Ordered List:</h3>
      <ol>
        {/* We map over the itemList array to display each item as a list item <li> */}
        {itemList.map((item, index) => (
          <li key={index}>{item}</li>
        ))}
      </ol>
    </div>
  );
}