<template>
    <form @submit.prevent="createForm">
        <label for="temperature_Min">Test</label>
        <input type="number" name="temperature_Min" v-model="settings_values.temperature_Min" />
        <input type="number" name="temperature_Avg" v-model="settings_values.temperature_Avg" />
        <input type="number" name="temperature_Max" v-model="settings_values.temperature_Max" />
        <input type="number" name="soilMoisture_Min" v-model="settings_values.soilMoisture_Min" />
        <input type="number" name="soilMoisture_Max" v-model="settings_values.soilMoisture_Max" />
        <input type="checkbox" name="setLufter_1" v-model="settings_values.setLufter_1" />
        <input type="checkbox" name="setLufter_2" v-model="settings_values.setLufter_2" />
        <input type="checkbox" name="setPumpe" v-model="settings_values.setPumpe" />
        <input type="checkbox" name="setLight" v-model="settings_values.setLight" />
        <input type="color" name="setRgbLed" v-model="fromData.rgb" />
        <input type="text" name="setMatrixLed" v-model="settings_values.setMatrixLed" />

        <!--input type="text" name="Name" v-model="settings_values.setMatrixLed" /-->
        <button type="submit">Submit</button>
    </form>
</template>

<script setup>
const runtimeConfig = useRuntimeConfig()
const {data: settings_data, refresh} = await useFetch(`${runtimeConfig.api_host}/settings`);
const settings_key = settings_data.key;
const settings_values = settings_data.value;
console.warn(settings_data);

let fromData = ref({
    rgb: ''
})

function createForm() {
    console.warn('Form created');
    console.warn(fromData.value);
}

function update() {
    const data = useFetch(
        `${runtimeConfig.api_host}/settings/1}`,
        { method: 'PATCH' },
    )
}

</script>