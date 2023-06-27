export default defineEventHandler(async (event) => {
    const setBody = readBody(event)
    console.log(setBody)
    const res = await $fetch('http://localhost:8080/settings', {
        method: 'PATCH',
        headers: {
            'Content-Type': 'application/json'
        },
        body: setBody
    });
    return res;
})