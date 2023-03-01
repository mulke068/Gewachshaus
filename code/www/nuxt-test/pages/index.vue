<template>
    <div>
        <h1>Test</h1>
        <button @click="$event => getData()">Get Data</button>
    </div>
</template>

<script>




export default {
    setup () {
        const data = {  }

        async function getData() {
            try {
                const response = await fetch('https://kevbchef.com/api', {
                    method: 'GET',
                    headers: {
                        'Content-Type': 'application/json',
                        'Access-Control-Allow-Origin': '*',
                        'Access-Control-Allow-Headers': '*',
                        'X-API-Key': 'Xg9sAxtcD3xFu45AEWg4y3nffVRiq'
                    },
                    body: JSON.stringify(data)
                });
                const responseData = await response.json()
                console.log(responseData);
                // Handle the response data here
            } catch (error) {
                console.log(error);
            }
        }
        getData()
        return {}
    }
}
</script>

<style scoped>

</style>