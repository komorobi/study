<template>
  <div class="change">
    <div>
      <div class="detail-head">物资列表</div>
      <div class="table-style">
        <table>
          <tr>
            <th>编号</th>
            <th>名称</th>
            <th>数量</th>
            <th>入库日期</th>
            <th>位置</th>
            <th>备注</th>
            <th>操作</th>
          </tr>
          <tr v-for="(item, index) in Data">
            <th>{{ index }}</th>
            <th>{{ item.name }}</th>
            <th>{{ item.number }}</th>
            <th>{{ item.indata }}</th>
            <th>{{ item.position }}</th>
            <th>{{ item.remarks }}</th>
            <th>
              <button @click="deleteitem(index)">删除</button>
              <button>出库/入库</button>
            </th>
          </tr>
        </table>
      </div>

      <div><button>
          <RouterLink to="/addItem">添加新物资</RouterLink>
        </button></div>
    </div>
  </div>
</template>

<script setup lang="ts">
//import type { routeLocationKey } from 'vue-router';
import { data } from '../components/list.json'
import { ref } from 'vue';
// import { useRoute } from 'vue-router'
// const route = useRoute()
const Data = ref(data)

function deleteitem(index: number) {
  Data.value.splice(index, 1)
}

</script>
<style>
.change {
  padding-top: 50px;
  margin-left: 200px;
}

.detail-head {
  font-size: 50px;
  text-align: center;
  padding-top: 90px;
  padding-bottom: 20px;
}

.table-style {
  display: flex;
  justify-content: center;
}



td,
th {
  background-color: (0, 0, 1, 0.2);
  border-style: none;
  border-color: aliceblue;
  padding-left: 10px;
  height: 50px;
  line-height: 50px;
  width: 150px;
}
</style>