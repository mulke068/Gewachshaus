<template>
    <div v-if="data_loaded">
        <div class="grid gap-2 md:grid-cols-3 hover:grid-cols-1 text-white-50">
            <div v-for="sensor in sensor_data" :key="sensor.id" >
                <div class="grid items-center justify-center w-auto h-auto gap-4 rounded-lg grid-row-4 hover:grid-flow-row hover:justify-between bg-minsk-900">
                    <div class="flex h-10 space-x-8">
                        <div class="m-2 ">ID</div>
                        <div class="m-2">{{ sensor.id }}</div>
                    </div>
                    <div class="flex h-10 space-x-8">
                        <div class="m-2">Value</div>
                        <div class="m-2">{{ sensor.value }}</div>
                    </div>
                    <div class="flex h-min[10] h-max[auto] space-x-8">
                        <div class="m-2">Description</div>
                        <div class="m-2">{{ sensor.description }}</div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div v-else class="animate-pulse">
        Loading ...
    </div>
</template>

<script lang="ts">
export default {
    data() {
        return {
            sensor_data: [
                {
                    id: String,
                    value: Number,
                    description: String
                }
            ],
            data_loaded: false
        }
    },
    mounted() {
        this.fetchData()
    },
    methods: {
        fetchData(){
            const runtimeConfig: any = useRuntimeConfig()
            fetch(`${runtimeConfig.api_host}/sensor`)
                .then(res => res.json())
                .then(data => {
                    this.sensor_data = data[0]["sensor"];
                    this.data_loaded = true;
                })
                .catch(err => {
                    console.log(err)
                })
            console.log("Get sensor Status 200");
        }
    }
}
</script>

<style scoped>

</style>