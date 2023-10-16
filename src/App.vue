<script setup lang="ts">
import { RouterLink, RouterView } from 'vue-router';
import home from './components/home.vue'
//import home from './components/home.vue';
</script>

<template>
  <header>

    <div class="header-font1">华南虎仓库管理系统</div>

  </header>

  <div class="sidebar">
    <div class="insidebar">
      <RouterLink to="/">首页</RouterLink>
    </div>
    <div class="insidebar">
      <RouterLink to="/manager">仓库管理</RouterLink>
    </div>
    <!-- <div class="insidebar">
      <RouterLink to="personal">个人中心</RouterLink>
    </div> -->
    <!-- <home /> -->

  </div>
  <div>
    <RouterView></RouterView>
  </div>
</template>

<style>
header {
  display: flex;
  position: fixed;
  padding-left: 20px;
  height: 50px;
  line-height: 50px;
  background-color: rgb(122, 109, 109);
  width: 100%;
}

.header-font1 {
  padding-left: 8px;
  color: aliceblue;
  font-size: 18px;
}


.header-font {
  padding-left: 150px;
  color: aliceblue;
  font-size: 20px;
}

.sidebar {
  margin: 0;
  padding-top: 100px;
  width: 200px;
  background-color: #f1f1f1;
  margin-top: 50px;
  position: fixed;
  height: 100%;
  overflow: auto;
}

.insidebar {
  padding: 15px;
  font-size: 15px;
}

body {
  background-color: white;
  color: black;
}

button {

  border-style: none;
  padding: 12px;
  text-decoration: none;
}

table tr {
  background-color: #f2f2f2;
}



.insidebar:hover {
  background-color: white;
}
</style>
