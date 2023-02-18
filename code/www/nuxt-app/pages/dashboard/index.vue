

<template>
    <div class=" text-white-50">
        <div class="text-xl">
            <div class="flex justify-center text-3xl ">Dashboard</div>
            <div class="grid grid-cols-4 gap-5">
                <!--p v-for="data in requestData" :key="data.id">
                    {{ data }}
                </p>
                <div v-for="p in data" :key="p.id">
                    <p>{{ p.title }}</p>
                </div-->
                
                <button @click="putData">PUT Data</button>
                <button @click="getData">GET Data</button>
                <p v-if="responseData" id="app">{{ responseData }}</p>
                <p v-if="fetchError" id="app">{{ fetchError }}</p>
                
            </div>
        </div>
    </div>
</template>


<script>



/*
let api_url = 'https://kevbchef.com/api/';

let options = {
    method: 'GET',
    headers: {
        'Content-Type': 'application/json',
        'Access-Control-Allow-Origin': '*',
        'Access-Control-Allow-Headers': '*',
        'X-API-Key': 'Xg9sAxtcD3xFu45AEWg4y3nffVRiq'
    }
};

const { data: requestsData } = await useFetch(api_url, options);
//const requestData = JSON.stringify(requestsData)
//console.log(requestData);

const { data, pending, error, refresh } = await useFetch('https://fakestoreapi.com/products')
console.log(data);
*/

//import { useFetch } from '@nuxtjs/composition-api'

export default {
  setup() {
    const { data: responseData, error: fetchError } = useFetch()

    const myFetch = async (url, data, method) => {
      const options = {
        method,
        headers: {
          'Content-Type': 'application/json',
          'Access-Control-Allow-Origin': '*',
          'Access-Control-Allow-Headers': '*',
          'X-API-Key': 'Xg9sAxtcD3xFu45AEWg4y3nffVRiq'
        },
        data
      }
      const {data:response} = await useFetch(url, options)
      return response
    }

    const putData = async () => {
      const data = { }
      const response = await myFetch('https://kevbchef.com/api/', data, 'PUT')
      console.log(response)
    }

    const getData = async () => {
      const data = {  }
      const response = await myFetch('https://kevbchef.com/api/index.php', data, 'GET')
      console.log(response["1"]["id"])
      console.log(responseData["1"]["id"])
    }

    return {
      responseData,
      fetchError,
      putData,
      getData
    }
  }
}


</script>

<style>

</style>