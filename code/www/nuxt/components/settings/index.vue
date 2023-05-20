<template>
    <form @submit.prevent="createForm">
        <input type="text" name="Name" placeholder="Name" v-model="fromData.name" />
        <input type="text" name="Email" placeholder="Email" v-model="fromData.email"/>
        <input type="text" name="Password" placeholder="Password" v-model="fromData.pwd"/>
        <button type="submit">Submit</button>
    </form>
</template>

<script setup>
let fromData = ref({
    name: '',
    email: '',
    pwd: ''
})
function createForm() {
    console.warn('Form created');
    console.warn(fromData.value.name);
}
</script>