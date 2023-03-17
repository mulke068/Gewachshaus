

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

</script>