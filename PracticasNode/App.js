const express = require('express')
const app = express()
let notes = [
    {
        id: 1,
        content: "El mike es gei",
        date: "2022-01-25T18:15:00",
        important: false
    },
    {
        id: 2,
        content: "Browser can execute only Javascript",
        date: "2022-01-25T18:16:00",
        important: false
    },
    {
        id: 3,
        content: "GET and POST are the most important methods of HTTP protocol",
        date: "2022-01-25T18:17:00",
        important: true
    }
]

app.get('/', (request, response) => {
    response.send('<h1>Buebos yo</h1>')
})

app.get('/api/notes', (request, response) => {
    response.json(notes)
})

app.get('/api/notes/:id', (request, response) => {
    const id = Number(request.params.id)
    const note = notes.find(note => note.id === id)
    if(note){ response.json(note) }
    else{ response.status(404).end() }
})

app.delete('/api/notes/:id', (request, response) => {
    const id = Number(request.params.id)
    notes = notes.filter(note => note.id !== id)

    response.status(204).end()
})

const PORT = 3001
app.listen(PORT)
console.log('Server running on port ', PORT)