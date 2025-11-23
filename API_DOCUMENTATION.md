# Linked Lists API Documentation

## Base URL
```
http://localhost:18080
```

---

## Root Endpoint

### Check Server Status
**GET** `/`

**Description:** Check if the server is running

**Request:**
```http
GET http://localhost:18080/
```

**Response:**
```json
{
  "message": "Crow is running",
  "status": "ok"
}
```

---

## Singly Linked List API

### 1. Get Singly Linked List
**GET** `/api/singly/get`

**Description:** Retrieve the current state of the singly linked list

**Request:**
```http
GET http://localhost:18080/api/singly/get
```

**Response:**
```json
{
  // Returns the JSON representation of the list
}
```

---

### 2. Insert at Beginning
**POST** `/api/singly/insert/beginning`

**Description:** Insert a value at the beginning of the singly linked list

**Request:**
```http
POST http://localhost:18080/api/singly/insert/beginning
Content-Type: application/json

{
  "value": 10
}
```

**Response:**
```json
{
  "success": true,
  "message": "Inserted at beginning",
  "list": {
    // Updated list representation
  }
}
```

---

### 3. Insert at End
**POST** `/api/singly/insert/end`

**Description:** Insert a value at the end of the singly linked list

**Request:**
```http
POST http://localhost:18080/api/singly/insert/end
Content-Type: application/json

{
  "value": 20
}
```

**Response:**
```json
{
  "success": true,
  "message": "Inserted at end",
  "list": {
    // Updated list representation
  }
}
```

---

### 4. Insert at Position
**POST** `/api/singly/insert/position`

**Description:** Insert a value at a specific position in the singly linked list

**Request:**
```http
POST http://localhost:18080/api/singly/insert/position
Content-Type: application/json

{
  "value": 15,
  "position": 2
}
```

**Response:**
```json
{
  "success": true,
  "message": "Inserted at position",
  "list": {
    // Updated list representation
  }
}
```

---

### 5. Delete at Beginning
**DELETE** `/api/singly/delete/beginning`

**Description:** Delete the first element from the singly linked list

**Request:**
```http
DELETE http://localhost:18080/api/singly/delete/beginning
```

**Response (Success):**
```json
{
  "success": true,
  "message": "Deleted from beginning",
  "list": {
    // Updated list representation
  }
}
```

**Response (Empty List):**
```json
{
  "success": false,
  "message": "List is empty",
  "list": {
    // Empty list representation
  }
}
```

---

### 6. Delete at End
**DELETE** `/api/singly/delete/end`

**Description:** Delete the last element from the singly linked list

**Request:**
```http
DELETE http://localhost:18080/api/singly/delete/end
```

**Response (Success):**
```json
{
  "success": true,
  "message": "Deleted from end",
  "list": {
    // Updated list representation
  }
}
```

**Response (Empty List):**
```json
{
  "success": false,
  "message": "List is empty",
  "list": {
    // Empty list representation
  }
}
```

---

### 7. Delete at Position
**DELETE** `/api/singly/delete/position/<position>`

**Description:** Delete an element at a specific position in the singly linked list

**Request:**
```http
DELETE http://localhost:18080/api/singly/delete/position/2
```

**Response (Success):**
```json
{
  "success": true,
  "message": "Deleted from position",
  "list": {
    // Updated list representation
  }
}
```

**Response (Invalid Position):**
```json
{
  "success": false,
  "message": "Invalid position",
  "list": {
    // Current list representation
  }
}
```

---

### 8. Delete by Value
**DELETE** `/api/singly/delete/value/<value>`

**Description:** Delete the first occurrence of a specific value from the singly linked list

**Request:**
```http
DELETE http://localhost:18080/api/singly/delete/value/15
```

**Response (Success):**
```json
{
  "success": true,
  "message": "Value deleted",
  "list": {
    // Updated list representation
  }
}
```

**Response (Value Not Found):**
```json
{
  "success": false,
  "message": "Value not found",
  "list": {
    // Current list representation
  }
}
```

---

### 9. Update Value
**PUT** `/api/singly/update`

**Description:** Update an old value with a new value in the singly linked list

**Request:**
```http
PUT http://localhost:18080/api/singly/update
Content-Type: application/json

{
  "oldValue": 10,
  "newValue": 25
}
```

**Response (Success):**
```json
{
  "success": true,
  "message": "Value updated",
  "list": {
    // Updated list representation
  }
}
```

**Response (Value Not Found):**
```json
{
  "success": false,
  "message": "Value not found",
  "list": {
    // Current list representation
  }
}
```

---

### 10. Search Value
**GET** `/api/singly/search/<value>`

**Description:** Search for a value in the singly linked list

**Request:**
```http
GET http://localhost:18080/api/singly/search/15
```

**Response:**
```json
{
  "found": true,
  "value": 15
}
```

---

### 11. Clear List
**DELETE** `/api/singly/clear`

**Description:** Clear all elements from the singly linked list

**Request:**
```http
DELETE http://localhost:18080/api/singly/clear
```

**Response:**
```json
{
  "success": true,
  "message": "List cleared",
  "list": {
    // Empty list representation
  }
}
```

---

## Doubly Linked List API

### 1. Get Doubly Linked List
**GET** `/api/doubly/get`

**Description:** Retrieve the current state of the doubly linked list

**Request:**
```http
GET http://localhost:18080/api/doubly/get
```

**Response:**
```json
{
  // Returns the JSON representation of the list
}
```

---

### 2. Insert at Beginning
**POST** `/api/doubly/insert/beginning`

**Description:** Insert a value at the beginning of the doubly linked list

**Request:**
```http
POST http://localhost:18080/api/doubly/insert/beginning
Content-Type: application/json

{
  "value": 10
}
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 3. Insert at End
**POST** `/api/doubly/insert/end`

**Description:** Insert a value at the end of the doubly linked list

**Request:**
```http
POST http://localhost:18080/api/doubly/insert/end
Content-Type: application/json

{
  "value": 20
}
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 4. Insert at Position
**POST** `/api/doubly/insert/position`

**Description:** Insert a value at a specific position in the doubly linked list

**Request:**
```http
POST http://localhost:18080/api/doubly/insert/position
Content-Type: application/json

{
  "value": 15,
  "position": 2
}
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 5. Delete at Beginning
**DELETE** `/api/doubly/delete/beginning`

**Description:** Delete the first element from the doubly linked list

**Request:**
```http
DELETE http://localhost:18080/api/doubly/delete/beginning
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 6. Delete at End
**DELETE** `/api/doubly/delete/end`

**Description:** Delete the last element from the doubly linked list

**Request:**
```http
DELETE http://localhost:18080/api/doubly/delete/end
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 7. Delete at Position
**DELETE** `/api/doubly/delete/position/<position>`

**Description:** Delete an element at a specific position in the doubly linked list

**Request:**
```http
DELETE http://localhost:18080/api/doubly/delete/position/2
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 8. Delete by Value
**DELETE** `/api/doubly/delete/value/<value>`

**Description:** Delete the first occurrence of a specific value from the doubly linked list

**Request:**
```http
DELETE http://localhost:18080/api/doubly/delete/value/15
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 9. Update Value
**PUT** `/api/doubly/update`

**Description:** Update an old value with a new value in the doubly linked list

**Request:**
```http
PUT http://localhost:18080/api/doubly/update
Content-Type: application/json

{
  "oldValue": 10,
  "newValue": 25
}
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 10. Search Value
**GET** `/api/doubly/search/<value>`

**Description:** Search for a value in the doubly linked list

**Request:**
```http
GET http://localhost:18080/api/doubly/search/15
```

**Response:**
```json
{
  "found": true
}
```

---

### 11. Clear List
**DELETE** `/api/doubly/clear`

**Description:** Clear all elements from the doubly linked list

**Request:**
```http
DELETE http://localhost:18080/api/doubly/clear
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Empty list representation
  }
}
```

---

## Circular Linked List API

### 1. Get Circular Linked List
**GET** `/api/circular/get`

**Description:** Retrieve the current state of the circular linked list

**Request:**
```http
GET http://localhost:18080/api/circular/get
```

**Response:**
```json
{
  // Returns the JSON representation of the list
}
```

---

### 2. Insert at Beginning
**POST** `/api/circular/insert/beginning`

**Description:** Insert a value at the beginning of the circular linked list

**Request:**
```http
POST http://localhost:18080/api/circular/insert/beginning
Content-Type: application/json

{
  "value": 10
}
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 3. Insert at End
**POST** `/api/circular/insert/end`

**Description:** Insert a value at the end of the circular linked list

**Request:**
```http
POST http://localhost:18080/api/circular/insert/end
Content-Type: application/json

{
  "value": 20
}
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 4. Insert at Position
**POST** `/api/circular/insert/position`

**Description:** Insert a value at a specific position in the circular linked list

**Request:**
```http
POST http://localhost:18080/api/circular/insert/position
Content-Type: application/json

{
  "value": 15,
  "position": 2
}
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 5. Delete at Beginning
**DELETE** `/api/circular/delete/beginning`

**Description:** Delete the first element from the circular linked list

**Request:**
```http
DELETE http://localhost:18080/api/circular/delete/beginning
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 6. Delete at End
**DELETE** `/api/circular/delete/end`

**Description:** Delete the last element from the circular linked list

**Request:**
```http
DELETE http://localhost:18080/api/circular/delete/end
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 7. Delete at Position
**DELETE** `/api/circular/delete/position/<position>`

**Description:** Delete an element at a specific position in the circular linked list

**Request:**
```http
DELETE http://localhost:18080/api/circular/delete/position/2
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 8. Delete by Value
**DELETE** `/api/circular/delete/value/<value>`

**Description:** Delete the first occurrence of a specific value from the circular linked list

**Request:**
```http
DELETE http://localhost:18080/api/circular/delete/value/15
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 9. Update Value
**PUT** `/api/circular/update`

**Description:** Update an old value with a new value in the circular linked list

**Request:**
```http
PUT http://localhost:18080/api/circular/update
Content-Type: application/json

{
  "oldValue": 10,
  "newValue": 25
}
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Updated list representation
  }
}
```

---

### 10. Search Value
**GET** `/api/circular/search/<value>`

**Description:** Search for a value in the circular linked list

**Request:**
```http
GET http://localhost:18080/api/circular/search/15
```

**Response:**
```json
{
  "found": true
}
```

---

### 11. Clear List
**DELETE** `/api/circular/clear`

**Description:** Clear all elements from the circular linked list

**Request:**
```http
DELETE http://localhost:18080/api/circular/clear
```

**Response:**
```json
{
  "success": true,
  "list": {
    // Empty list representation
  }
}
```

---

## Error Responses

### 400 Bad Request
Returned when the request body is missing or invalid JSON.

**Example:**
```json
{
  // Empty response or error message
}
```

---

## Testing Tips

1. **Start with GET requests** to check the current state of lists
2. **Insert values** using POST requests before testing delete operations
3. **Use position-based operations** carefully - positions are typically 0-indexed or 1-indexed depending on implementation
4. **Test edge cases** like empty lists, invalid positions, and non-existent values
5. **Clear lists** between test sessions using the clear endpoint

---

## Postman Collection Import

You can use these endpoints to create a Postman collection. Here's a quick reference:

- **Base URL Variable:** `{{baseUrl}}` = `http://localhost:18080`
- **Headers:** Set `Content-Type: application/json` for POST and PUT requests
- **Body Type:** Use `raw` with `JSON` format for POST and PUT requests

---

## Example Test Sequence

### Singly Linked List Test Flow:
1. `GET /api/singly/get` - Check initial state
2. `POST /api/singly/insert/beginning` with `{"value": 10}`
3. `POST /api/singly/insert/end` with `{"value": 20}`
4. `POST /api/singly/insert/position` with `{"value": 15, "position": 1}`
5. `GET /api/singly/search/15` - Search for value
6. `PUT /api/singly/update` with `{"oldValue": 15, "newValue": 25}`
7. `DELETE /api/singly/delete/value/25`
8. `GET /api/singly/get` - Verify final state
9. `DELETE /api/singly/clear` - Clean up

Repeat similar flows for Doubly and Circular linked lists.

