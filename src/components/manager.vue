<template>
  <div class="manager">
    <div>
      <div class="manager-header">仓库列表</div>
    </div>
    <div class="manager-table">
      <table>
        <tr class="manger-tr">
          <th style="width: 10px;">编号</th>
          <th>名称</th>
          <th>管理员</th>
          <th>备注</th>
          <th>编辑</th>

        </tr>
        <tr v-for="(item, index) in Repository" :key="item.ID" class="manger-tr">
          <td>{{ index }}</td>
          <td id="name">{{ item.name }}</td>
          <td id="owner">{{ item.uuid }} <button @click="changeAdmin(index)">调整管理员</button></td>
          <td id="remarks">{{ item.info }}</td>
          <td class="td-set">
            <button>
              <RouterLink to="/detail">物资详情</RouterLink>
            </button>
            <button @click="deleterepository(index)">删除仓库</button>
          </td>
        </tr>
      </table>
    </div>

    <div class="add-div">
      <button class="add-button">
        <RouterLink to="/addRepository">添加仓库</RouterLink>
      </button>
    </div>
  </div>
</template>

<script setup lang="ts">
//import { repository } from './list.json';
import { useRouter } from 'vue-router';
import Service from '@/api/config';
//import request from '../'
import { ref } from 'vue'
let Repository: []
Service.get('/getRepository')
  .then(function (response) {

    Repository = response.data
  })
function deleterepository(index: number) {
  Repository.splice(index, 1)
  //return Repository
}

function changeAdmin(index: number) {
  Repository.value[index].owner = ""

}


const router = useRouter();
type Item = {

  name: string,
  owner: string,
  remarks: string
}
// function todetail(item : Item) {
//   router.push({
//     path: '/detail',
//     query: item
//   })
// }



</script>

<style>
.manager {
  padding-top: 50px;
  margin-left: 200px;
}

/* .manager-tr {} */

.manager-header {
  padding-top: 90px;
  padding-bottom: 20px;
  text-align: center;
  font-size: 50px;
}

.manager-table {
  display: flex;
  justify-content: center;

}

td,
th {
  /* border: 1px solid black; */
  padding-left: 10px;
  height: 50px;
  line-height: 50px;
  width: 200px;
}

.td-set {
  width: 100px;
}

.manager-tr {
  background-color: #f2f2f2;
}

.add-div {}

.add-button {}
</style>
