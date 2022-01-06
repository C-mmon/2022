const load = async (apiEndpoint, callbackFn) => {
  const result = await fetch(apiEndpoint);
  if(!result.ok){
    throw new Error(`An error occurred: ${result.status}`)
  }
  // at this point, we have a good result:
  const jsonObj = await result.json();
  // run our callback function, passing in that object
  callbackFn(jsonObj)
}

// Let's use that. First, we'll make a callback function:
const todoHandler = (todos) => {
  const todoContainer = document.querySelector(".todos-container");

  todos.forEach( (todo)=>{
    const todoEl = document.createElement("div");
    todoEl.classList.add("todo");
    const todoTitle = document.createElement("h3");
    todoTitle.classList.add("todo-title");
    todoTitle.textContent=todo.title;

    const todoStatus = document.createElement("div");
    todoStatus.classList.add("todo-status");
    todoStatus.textContent = todo.done ? "Complete" : "Incomplete";

    todoEl.append(todoTitle, todoStatus);
    todoContainer.append(todoEl)
  })    
}

load("https://jsonplaceholder.typicode.com/todos", todoHandler);
