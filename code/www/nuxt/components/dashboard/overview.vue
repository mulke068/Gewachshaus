<template>
    <div v-if="dataLoaded">
        <div class="container flex">
            <div class="container py-2 md:w-40 bg-clementine-700">
                <div>
                    <div class="flex justify-center text-3xl">Devices</div>
                    <div class="p-4 text-lg ">
                        <div class="flex justify-center p-3 ">{{ data.devices.esp32[0].connected }}</div>
                        <div class="flex justify-center p-3">{{ data.devices.esp32[0].connected }}</div>
                        <div class="flex justify-center p-3">{{ data.devices.raspberrypi.connected }}</div>
                    </div>
                </div>
            </div>
            <div class="container p-2 px-3 bg-minsk-900">
                <div>
                    <div class="flex justify-start text-3xl">TempHum</div>
                    <div class="flex justify-center p-4 space-x-4 text-lg">
                        <DashboardCirqualPorgress :value="data.tempHum.temperature_1" :max="80" :min="0" :unit="'°C'" />
                        <DashboardCirqualPorgress :value="data.tempHum.humidity_1" :max="100" :min="0" :unit="'%'" />
                        <DashboardCirqualPorgress :value="data.tempHum.temperature_2" :max="80" :min="0" :unit="'°C'" />
                        <DashboardCirqualPorgress :value="data.tempHum.humidity_2" :max="100" :min="0" :unit="'%'" />
                    </div>
                </div>
                <div>
                    <div class="flex justify-start text-3xl">WaterSystem</div>
                    <div class="flex justify-center p-4 space-x-4 text-lg">
                        <div>{{ data.waterSystem.sensor_1 }}</div>
                        <div>{{ data.waterSystem.sensor_2 }}</div>
                        <div>{{ data.waterSystem.pumpe }}</div>
                    </div>
                </div>
                <div>
                    <div class="flex justify-start text-3xl">LufterLeds</div>
                    <div class="flex justify-center p-4 space-x-4 text-lg">
                        <div>{{ data.lufterLeds.getLufter_1 }}</div>
                        <div>{{ data.lufterLeds.setLufter_1 }}</div>
                        <div>{{ data.lufterLeds.getLufter_2 }}</div>
                        <div>{{ data.lufterLeds.setLufter_2 }}</div>
                        <div>{{ data.lufterLeds.getLed }}</div>
                        <div>{{ data.lufterLeds.setLed }}</div>
                    </div>    
                </div>
                <div>
                    <div class="flex justify-start text-3xl">EnergieStatus</div>
                    <div class="flex justify-center p-4 space-x-4 text-lg">
                        <div>{{ data.energieStatus.solar_1 }}</div>
                        <div>{{ data.energieStatus.solar_2 }}</div>
                        <div>{{ data.energieStatus.akku }}</div>
                        <div>{{ data.energieStatus.strom }}</div>
                    </div>
                </div>
                <div>
                    <div class="flex justify-start text-3xl">Settings</div>
                    <div class="flex justify-center p-4 space-x-4 text-lg">
                        <div>{{ data.settings.brightness }}</div>
                        <div>{{ data.settings.sound }}</div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div v-else class="animate-pulse">
        Loading...
    </div>
</template>

<script>
export default {
    mode: 'client',
    data() {
        return {
        data: [],
        dataLoaded: false
        }
    },
    mounted() {
        this.fetchData()

        setInterval(() => {
            this.fetchData()
        }, 5000)
    },
    methods: {
        fetchData() {
            fetch('http://localhost:8080/random')
            .then(response => response.json())
            .then(data => {
                this.data = data[0]
                this.dataLoaded = true
            })
        }
    }
}

</script>

<style scoped>

</style>

<!--
    <div>
        <div v-if="dataLoaded">
        <div v-for="data in data" :key="data._id">
            <div>{{ data.tempHum.temperature_1 }}</div>
            <div>{{ data.tempHum.humidity_1 }}</div>
            <div>{{ data.tempHum.temperature_2 }}</div>
            <div>{{ data.tempHum.humidity_2 }}</div>
        </div>
    </div>
    <div v-else>
        Loading...
    </div>
    </div>
-->


<!--template>
    <div class="container py-2 md:w-40 bg-clementine-700">
        <div>
            <div class="flex justify-center text-3xl">Devices</div>
            <div class="p-4 text-lg ">
                <div class="flex justify-center p-3 ">{{ devices.esp32[0].connected }}</div>
                <div class="flex justify-center p-3">{{ devices.esp32[0].connected }}</div>
                <div class="flex justify-center p-3">{{ devices.raspberrypi.connected }}</div>
            </div>
        </div>
    </div>
    <div class="container p-2 px-3 bg-minsk-900">
        <div>
            <div class="flex justify-start text-3xl">TempHum</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ tempHum.temperature_1 }}</div>
                <div>{{ tempHum.humidity_1 }}</div>
                <div>{{ tempHum.temperature_2 }}</div>
                <div>{{ tempHum.humidity_2 }}</div>
            </div>
        </div>
        <div>
            <div class="flex justify-start text-3xl">WaterSystem</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ waterSystem.sensor_1 }}</div>
                <div>{{ waterSystem.sensor_2 }}</div>
                <div>{{ waterSystem.pumpe }}</div>
            </div>
        </div>
        <div>
            <div class="flex justify-start text-3xl">LufterLeds</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ lufterLeds.getLufter_1 }}</div>
                <div>{{ lufterLeds.setLufter_1 }}</div>
                <div>{{ lufterLeds.getLufter_2 }}</div>
                <div>{{ lufterLeds.setLufter_2 }}</div>
                <div>{{ lufterLeds.getLed }}</div>
                <div>{{ lufterLeds.setLed }}</div>
            </div>    
        </div>
        <div>
            <div class="flex justify-start text-3xl">EnergieStatus</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ energieStatus.solar_1 }}</div>
                <div>{{ energieStatus.solar_2 }}</div>
                <div>{{ energieStatus.akku }}</div>
                <div>{{ energieStatus.strom }}</div>
            </div>
        </div>
        <div>
            <div class="flex justify-start text-3xl">Settings</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ settings.brightness }}</div>
                <div>{{ settings.sound }}</div>
            </div>
        </div>
    </div>
</template-->

<!--script setup>
const { data: data_items ,error, refresh, pending } = await useFetch('/api/data')
const items = data_items._rawValue.data[0]
const devices = items.devices
const tempHum = items.tempHum
const waterSystem = items.waterSystem
const lufterLeds = items.lufterLeds
const energieStatus = items.energieStatus
const settings = items.settings
console.log(items)
</script-->


<!--script>
export default {
    data() {
        return {
            devices: [],
            tempHum: [],
            waterSystem: [],
            lufterLeds: [],
            energieStatus: [],
            settings: [],
        }
    },
    async mounted() {
        const { data: data_items ,error, refresh, pending } = await useFetch('/api/data')
        const items = data_items._rawValue.data[0]
        this.devices = items.devices
        this.tempHum = items.tempHum
        this.waterSystem = items.waterSystem
        this.lufterLeds = items.lufterLeds
        this.energieStatus = items.energieStatus
        this.settings = items.settings
        console.log(items)
    },
    fetchOnServer: false,
}
</script-->


<!--script>
export default {
    mode: 'client',
    data() {
        return {
            devices: null,
            tempHum: null,
            waterSystem: null,
            lufterLeds: null,
            energieStatus: null,
            settings: null
        }
    },
    async mounted() {
        const { data: data_items } = await this.$fetch('/api/data')
        const items = data_items._rawValue.data[0]
        this.devices = items.devices
        this.tempHum = items.tempHum
        this.waterSystem = items.waterSystem
        this.lufterLeds = items.lufterLeds
        this.energieStatus = items.energieStatus
        this.settings = items.settings
        console.log(this.devices, this.tempHum, this.waterSystem, this.lufterLeds, this.energieStatus, this.settings)
    }
}
</script-->